#ifndef __compat_h__
#define __compat_h__

#include <strings.h>

#define stricmp strcasecmp
#define strcmpi strcasecmp
#define memicmp memcmpi

#ifndef _MAX_DIR
#define _MAX_DIR 256
#endif
#ifndef _MAX_EXT
#define _MAX_EXT 256
#endif
#ifndef _MAX_DRIVE
#define _MAX_DRIVE 3
#endif
#ifndef _MAX_FNAME
#define _MAX_FNAME 256
#endif
#ifndef _MAX_PATH
#define _MAX_PATH 260
#endif
#ifndef MAX_PATH
#define MAX_PATH _MAX_PATH
#endif

void _splitpath(const char *, char *, char *, char *, char *);
void _makepath(char *, const char *, const char *, const char *, const char *);
int getch(void);
int memcmpi(const void *, const void *, size_t);
char *strupr(char *);
char *strlwr(char *);
#endif
