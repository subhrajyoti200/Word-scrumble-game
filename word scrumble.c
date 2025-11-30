#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void scrambleWord(char *word, char *scrambled) {
    strcpy(scrambled, word);
    int len = strlen(scrambled);
    
    for (int i = 0; i < len; i++) {
        int j = rand() % len;
        char temp = scrambled[i];
        scrambled[i] = scrambled[j];
        scrambled[j] = temp;
    }
}

int main() {
    char words[][20] = {"computer", "programming", "college", "science",
                        "language", "keyboard", "internet", "project",
                        "engineer", "software"};
    int totalWords = sizeof(words) / sizeof(words[0]);
    
    char guess[20], scrambled[20];
    int score = 0;
    
    srand(time(0));
    
    printf("\n===== WORD SCRAMBLE GAME =====\n");
    printf("Unscramble the letters and type the correct word!\n");
    printf("Type 'exit' anytime to quit.\n\n");
    
    for (int i = 0; i < 5; i++) {
        int index = rand() % totalWords;
        scrambleWord(words[index], scrambled);
        
        printf("Scrambled Word %d: %s\n", i + 1, scrambled);
        printf("Your Guess: ");
        scanf("%s", guess);
        
        if (strcmp(guess, "exit") == 0) {
            printf("\nGame Exited.\n");
            break;
        }
        
        if (strcmp(guess, words[index]) == 0) {
            printf("✔ Correct!\n\n");
            score++;
        } else {
            printf("✘ Wrong! The correct word is: %s\n\n", words[index]);
        }
    }
    
    printf("===== GAME OVER =====\n");
    printf("Your Final Score: %d/5\n", score);
    
    if (score == 5)
        printf("Outstanding! 🔥\n");
    else if (score >= 3)
        printf("Good job! 😎\n");
    else
        printf("Keep practicing! 💪\n");
    
    return 0;
}
