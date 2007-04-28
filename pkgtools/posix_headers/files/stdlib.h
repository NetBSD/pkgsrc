/* $NetBSD: stdlib.h,v 1.1 2007/04/28 21:03:56 tnn Exp $ */
#ifndef _PKGSRC_STDLIB_H_
#define _PKGSRC_STDLIB_H_
#include "@REAL_HEADER@"
#ifdef __hpux
/* What were they thinking? */
#include <inttypes.h>
#define strtoll __strtoll
#define strtoull __strtoull
#include <string.h>
#include <stdio.h>
/* provide a setenv(3) implementation */
static __inline int setenv(const char *name, const char *value, int overwrite);
static __inline int setenv(const char *name, const char *value, int overwrite) {
	char *c;
	int ret;
	if (!overwrite && getenv(name)) return(-1);
	c = malloc(strlen(name)+strlen(value)+2);
	if(!c) return(-1);
	sprintf(c, "%s=%s", name, value);
	ret = putenv(c);
	free(c);
	return(ret);
}
#endif /* __hpux */
#endif /* _PKGSRC_STDLIB_H_ */
