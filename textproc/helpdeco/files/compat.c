#include <ctype.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include "compat.h"

void _splitpath(
	const char *path,
	char *drive,
	char *dir,
	char *file,
	char *ext)
{
	char *p;
	char *t;

	if (path == NULL)
		return;

	if (drive != NULL)
		strcpy(drive, "");

	if (dir != NULL) {
		p = strdup(path);
		strncpy(dir, strdup(dirname(p)), _MAX_DIR);
		free(p);
	}

	if (ext != NULL) {
		p = strdup(path);
		t = strrchr(basename(p), '.');
		if (t == NULL) {
			strcpy(ext, "");
		} else {
			strncpy(ext, strdup(t), _MAX_EXT);
		}
		free(p);
	}

	if (file != NULL) {
		p = strdup(path);
		t = strrchr(p, '.');
		if (t != NULL && strchr(t, '/') == NULL) {
			*t = '\000';
		}
		strncpy(file, strdup(basename(p)), _MAX_FNAME);
		free(p);
	}

	return;
}

void _makepath(
	char *path,
	const char *drive,
	const char *dir,
	const char *file,
	const char *ext)
{
	snprintf(path, _MAX_PATH, "%s%s/%s%s",
		drive,
		dir,
		file,
		ext);
	return;
}

int getch(void)
{
	int retval;
        struct termios stored_settings;
        struct termios new_settings;
        
        tcgetattr(0, &stored_settings);
        new_settings = stored_settings;
        new_settings.c_lflag &= (~(ECHO|ICANON));
        new_settings.c_cc[VTIME] = 0;
        new_settings.c_cc[VMIN] = 1;
        tcsetattr(0, TCSANOW, &new_settings);

	retval = getchar();

        tcsetattr(0, TCSANOW, &stored_settings);

	return retval;
}

int memcmpi(
	const void *s1,
	const void *s2,
	size_t len)
{
	char *p1 = strdup(s1);
	char *p2 = strdup(s2);
	int i;

	for (i = 0; i < len; i++) {
		if (p1[i] == '\000') p1[i] = ' ';
		if (p2[i] == '\000') p2[i] = ' ';
	}
	i = strncasecmp(p1, p2, len);
	free(p1);
	free(p2);
	return i;
}

char *strupr(char *s)
{
	char *p;
	while (*p != '\000') *p = toupper(*p++);
	return s;
}

char *strlwr(char *s)
{
	char *p;
	while (*p != '\000') *p = tolower(*p++);
	return s;
}
