#include <iostream>

#include "src/matrix.hpp"

const int size = 10;

int main() {
    Matrix<int, 0> main_matrix;

    // Заполнение главной диагонали матрицы
    for(int i = 0; i < size; i++) {
        main_matrix[i][i] = i;
    }

    // Заполнение второстепенной диагонали матрицы
    for(int i = size - 1; i >= 0; i--) {
        main_matrix[i][size - i - 1] = i;
    }

    // Вывод матрицы 8х8
    std::cout << "Matrix result: " << std::endl;
    for(int i = 1; i < size - 1; i++) {
        for(int j = 1; j < size - 1; j++) {
            if(j > 1) std::cout << " ";
            std::cout << main_matrix[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Вывод количества занятых ячеек
    std::cout << "Matrix busy cells: " << main_matrix.size() << std::endl;
    std::cout << std::endl;

    // Вывод ячейки с номером и значением
    std::cout << "Matrix elements result:" << std::endl;
    for(auto const elements: main_matrix)
    {
        int i, j, value;
        std::tie(i, j, value) = elements;
        std::cout << "element on cell: [" << i << "][" << j << "] = " << value << std::endl;
    }

    return 0;
}