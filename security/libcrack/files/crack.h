#ifndef CRACKLIB_H
#define CRACKLIB_H

/* Pass this function a password (pw) and a path to the dictionaries,
 * and it will either return a NULL string, meaning that the password
 * is good, or a pointer to a string that explains the problem with
 * the password.
 * You must link with -lcrack
 */

extern char *FascistCheck (const char *pw, const char *dictpath);

#endif
