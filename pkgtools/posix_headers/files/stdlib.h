/* $NetBSD: stdlib.h,v 1.3 2007/04/28 23:33:36 tnn Exp $ */
#ifndef _PKGSRC_STDLIB_H_
#define _PKGSRC_STDLIB_H_
#include "@REAL_HEADER@"
#ifdef __hpux
/* What were they thinking? */
#include <inttypes.h>
#define strtoll __strtoll
#define strtoull __strtoull
/* provide a setenv(3) implementation */
#if 0
/*
 * XXX: disabled because some GNU configure scripts don't pick this up,
 * they look for the symbol in the c library. A better solution is needed.
 */
#include <string.h>
#include <stdio.h>
static __inline int setenv(const char *name, const char *value, int overwrite);
static __inline int setenv(const char *name, const char *value, int overwrite) {
	char *c;
	int ret;
	if (!overwrite && getenv(name)) return(-1);
	c = (char*)malloc(strlen(name)+strlen(value)+2);
	if(!c) return(-1);
	sprintf(c, "%s=%s", name, value);
	ret = putenv(c);
	free(c);
	return(ret);
}
#endif /* 0 */
#endif /* __hpux */
#endif /* _PKGSRC_STDLIB_H_ */
