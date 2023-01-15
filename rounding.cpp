// Copyright (c) 2019 Zaida Hammel All rights reserved.
//
// Created by: Zaida Hammel
// Created on: Jan 2023
// This program rounds numbers given by the user

#include <iostream>
#include <iomanip>
#include <cmath>

float Rounding(float & number, float decimalPoint) {
    // This function rounds the user's number

    float roundedNumber;

    // Process
    roundedNumber = number*pow(10, decimalPoint);
    roundedNumber = roundedNumber + 0.5;
    roundedNumber = static_cast<int>(roundedNumber);
    roundedNumber = roundedNumber/pow(10, decimalPoint);

    return roundedNumber;
}

int main() {
    // This function takes the user's number then outputs the number rounded

    std::string userNumberAsString;
    std::string decimalPlaceAsString;
    float userRoundedNumber;
    float userNumber;
    int decimalPlace;

    // Process
    while (true) {
        std::cout << "Enter the number you wish to be rounded:" << std::endl;
        std::cin >> userNumberAsString;
        std::cout << "Enter how many decimal places you want left:" \
        << std::endl;
        std::cin >> decimalPlaceAsString;

        try {
            userNumber = std::stof(userNumberAsString);
            decimalPlace = std::stoi(decimalPlaceAsString);
            if (userNumber == std::stof(userNumberAsString) && \
                decimalPlace == std::stoi(decimalPlaceAsString)) {
                    userRoundedNumber = Rounding(userNumber, decimalPlace);
                    std::cout << "" << std::endl;
                    std::cout << "Your number rounded is " \
                    << userRoundedNumber << std::endl;
                    break;
                } else {
                    std::cout << "Error, unable to process inputs" << std::endl;
                }
        } catch (std::invalid_argument) {
            std::cout << "Error, unable to process inputs" << std::endl;
            std::cout << "" << std::endl;
        }
    }
}
