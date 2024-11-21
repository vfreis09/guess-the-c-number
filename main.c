#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    int guess, answer;

    // Seed the random number generator
    srand(time(NULL));

    // Generate a random number in a specific range (e.g., 1 to 100)
    int lower = 1, upper = 100;
    answer = (rand() % (upper - lower + 1)) + lower;

    do {
        printf("Guess the number (1-100): ");

        // Validate input and ensure only numbers are accepted
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input. Please enter a number.\n");

            // Clear the input buffer
            while (getchar() != '\n');
            continue; // Restart the loop
        }

        if (guess < lower || guess > upper) {
            printf("Please enter a number between %d and %d.\n", lower, upper);
            continue;
        }

        if (guess == answer) {
            printf("You got it right!!!\n");
        } else if (guess > answer) {
            printf("Lower!\n");
        } else {
            printf("Higher!\n");
        }
    } while (guess != answer);

    return 0;
}