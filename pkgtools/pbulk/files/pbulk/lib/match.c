/* $NetBSD: match.c,v 1.1.1.1 2007/06/19 19:49:59 joerg Exp $ */

/*
 * Copyright © 2002 Alistair G. Crooks.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote
 *    products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <ctype.h>
#include <err.h>
#include <fnmatch.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "pbulk.h"

static int dewey_cmp(const char *, int, const char *);
static int dewey_match(const char *, const char *);
static int dewey_mktest(int *, const char *);

enum {
	MaxPathSize = PATH_MAX
};

enum {
	DEWEY_LT,
	DEWEY_LE,
	DEWEY_EQ,
	DEWEY_GE,
	DEWEY_GT,
	DEWEY_NE
};

const char *
pkg_order(const char *match1, const char *match2)
{
	const char *v1, *v2;

	v1 = strrchr(match1, '-');
	v2 = strrchr(match2, '-');

	if (v1 == NULL || v2 == NULL)
		errx(1, "Internal error");

	if (dewey_cmp(v1, DEWEY_GT, v2))
		return match1;
	else
		return match2;
}

#ifndef MIN
#define MIN(a,b)	(((a) < (b)) ? (a) : (b))
#endif

#ifndef MAX
#define MAX(a,b)	(((a) > (b)) ? (a) : (b))
#endif

#define NEWARRAY(type,ptr,size,where,action) do {			\
	if ((ptr = (type *) calloc(sizeof(type), (unsigned)(size))) == NULL) { \
		warn("%s: can't allocate %lu bytes", where,		\
			(unsigned long)(size * sizeof(type)));		\
		action;							\
	}								\
} while( /* CONSTCOND */ 0)

#define RENEW(type,ptr,size,where,action) do {				\
	type *newptr;							\
	if ((newptr = (type *) realloc(ptr, sizeof(type) * (size))) == NULL) { \
		warn("%s: can't realloc %lu bytes", where,		\
			(unsigned long)(size * sizeof(type)));		\
		action;							\
	}								\
	ptr = newptr;							\
} while( /* CONSTCOND */ 0)

#define NEW(type, ptr, where, action)	NEWARRAY(type, ptr, 1, where, action)

#define FREE(ptr)	(void) free(ptr)

#define ALLOC(type, v, size, c, init, where, action) do {		\
	if (size == 0) {						\
		size = init;						\
		NEWARRAY(type, v, size, where ": new", action);		\
	} else if (c == size) {						\
		size *= 2;						\
		RENEW(type, v, size, where ": renew", action);		\
	}								\
} while( /* CONSTCOND */ 0)


#define PKG_PATTERN_MAX 1024
typedef int (*matchfn) (const char *, void *);

/* do not modify these values, or things will NOT work */
enum {
        Alpha = -3,
        Beta = -2,
        RC = -1,
        Dot = 0,
        Patch = 1
};

/* this struct defines a version number */
typedef struct arr_t {
	unsigned	c;              /* # of version numbers */
	unsigned	size;           /* size of array */
	int	       *v;              /* array of decimal numbers */
	int		netbsd;         /* any "nb" suffix */
} arr_t;

/* this struct describes a test */
typedef struct test_t {
	const char     *s;              /* string representation */
	unsigned	len;            /* length of string */
	int		t;              /* enumerated type of test */
} test_t;


/* the tests that are recognised. */
static const test_t   tests[] = {
        {	"<=",	2,	DEWEY_LE	},
        {	"<",	1,	DEWEY_LT	},
        {	">=",	2,	DEWEY_GE	},
        {	">",	1,	DEWEY_GT	},
        {	"==",	2,	DEWEY_EQ	},
        {	"!=",	2,	DEWEY_NE	},
        {	NULL,	0,	0	}
};

static const test_t	modifiers[] = {
	{	"alpha",	5,	Alpha	},
	{	"beta",		4,	Beta	},
	{	"pre",		3,	RC	},
	{	"rc",		2,	RC	},
	{	"pl",		2,	Dot	},
	{	"_",		1,	Dot	},
	{	".",		1,	Dot	},
	{	NULL,		0,	0	}
};



/* locate the test in the tests array */
static int
dewey_mktest(int *op, const char *test)
{
	const test_t *tp;

	for (tp = tests ; tp->s ; tp++) {
		if (strncasecmp(test, tp->s, tp->len) == 0) {
			*op = tp->t;
			return tp->len;
		}
	}
	return -1;
}

/*
 * make a component of a version number.
 * '.' encodes as Dot which is '0'
 * '_' encodes as 'patch level', or 'Dot', which is 0.
 * 'pl' encodes as 'patch level', or 'Dot', which is 0.
 * 'alpha' encodes as 'alpha version', or Alpha, which is -3.
 * 'beta' encodes as 'beta version', or Beta, which is -2.
 * 'rc' encodes as 'release candidate', or RC, which is -1.
 * 'nb' encodes as 'netbsd version', which is used after all other tests
 */
static int
mkcomponent(arr_t *ap, const char *num)
{
	static const char       alphas[] = "abcdefghijklmnopqrstuvwxyz";
	const test_t	       *modp;
	int                 n;
	const char             *cp;

	if (*num == 0) {
		return 0;
	}
	ALLOC(int, ap->v, ap->size, ap->c, 62, "mkver", exit(EXIT_FAILURE));
	if (isdigit((unsigned char)*num)) {
		for (cp = num, n = 0 ; isdigit((unsigned char)*num) ; num++) {
			n = (n * 10) + (*num - '0');
		}
		ap->v[ap->c++] = n;
		return (int)(num - cp);
	}
	for (modp = modifiers ; modp->s ; modp++) {
		if (strncasecmp(num, modp->s, modp->len) == 0) {
			ap->v[ap->c++] = modp->t;
			return modp->len;
		}
	}
	if (strncasecmp(num, "nb", 2) == 0) {
		for (cp = num, num += 2, n = 0 ; isdigit((unsigned char)*num) ; num++) {
			n = (n * 10) + (*num - '0');
		}
		ap->netbsd = n;
		return (int)(num - cp);
	}
	if (isalpha((unsigned char)*num)) {
		ap->v[ap->c++] = Dot;
		cp = strchr(alphas, tolower((unsigned char)*num));
		ALLOC(int, ap->v, ap->size, ap->c, 62, "mkver", exit(EXIT_FAILURE));
		ap->v[ap->c++] = (int)(cp - alphas) + 1;
		return 1;
	}
	return 1;
}

/* make a version number string into an array of comparable 64bit ints */
static int
mkversion(arr_t *ap, const char *num)
{
	(void) memset(ap, 0, sizeof(arr_t));
	while (*num) {
		num += mkcomponent(ap, num);
	}
	return 1;
}

#define DIGIT(v, c, n) (((n) < (c)) ? v[n] : 0)

/* compare the result against the test we were expecting */
static int
result(int cmp, int tst)
{
	switch(tst) {
	case DEWEY_LT:
		return cmp < 0;
	case DEWEY_LE:
		return cmp <= 0;
	case DEWEY_GT:
		return cmp > 0;
	case DEWEY_GE:
		return cmp >= 0;
	case DEWEY_EQ:
		return cmp == 0;
	case DEWEY_NE:
		return cmp != 0;
	default:
		return 0;
	}
}

/* do the test on the 2 vectors */
static int
vtest(arr_t *lhs, int tst, arr_t *rhs)
{
	int cmp;
	int     c;
	int     i;

	for (i = 0, c = MAX(lhs->c, rhs->c) ; i < c ; i++) {
		if ((cmp = DIGIT(lhs->v, lhs->c, i) - DIGIT(rhs->v, rhs->c, i)) != 0) {
			return result(cmp, tst);
		}
	}
	return result(lhs->netbsd - rhs->netbsd, tst);
}

/*
 * Compare two dewey decimal numbers
 */
static int
dewey_cmp(const char *lhs, int op, const char *rhs)
{
	arr_t	right;
	arr_t	left;

	(void) memset(&left, 0, sizeof(left));
	if (!mkversion(&left, lhs)) {
		return 0;
	}
	(void) memset(&right, 0, sizeof(right));
	if (!mkversion(&right, rhs)) {
		return 0;
	}
        return vtest(&left, op, &right);
}

/*
 * Perform dewey match on "pkg" against "pattern".
 * Return 1 on match, 0 on non-match, -1 on error.
 */
static int
dewey_match(const char *pattern, const char *pkg)
{
	const char *version;
	const char *sep, *sep2;
	int op, op2;
	int n;

	/* compare names */
	if ((version=strrchr(pkg, '-')) == NULL) {
		return 0;
	}
	if ((sep = strpbrk(pattern, "<>")) == NULL)
		return -1;
	/* compare name lengths */
	if ((sep-pattern != version-pkg) ||
	    strncmp(pkg, pattern, (size_t)(version-pkg)) != 0)
		return 0;
	version++;
	
	/* extract comparison operator */
        if ((n = dewey_mktest(&op, sep)) < 0) {
		return 0;
        }
	/* skip operator */
	sep += n;

	/* if greater than, look for less than */
	sep2 = NULL;
	if (op == DEWEY_GT || op == DEWEY_GE) {
		if ((sep2 = strchr(sep, '<')) != NULL) {
			if ((n = dewey_mktest(&op2, sep2)) < 0) {
				return 0;
			}
			/* compare upper limit */
			if (!dewey_cmp(version, op2, sep2+n))
				return 0;
		}
	}

	/* compare only pattern / lower limit */
	if (sep2) {
		char ver[PKG_PATTERN_MAX];

		strlcpy(ver, sep, MIN(sizeof(ver), sep2-sep+1));
		if (dewey_cmp(version, op, ver))
			return 1;
	}
	else {
		if (dewey_cmp(version, op, sep))
			return 1;
	}

	return 0;
}


/*
 * FreeBSD install - a package for the installation and maintainance
 * of non-core utilities.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * Jordan K. Hubbard
 * 18 July 1993
 *
 * Miscellaneous string utilities.
 *
 */


/*
 * Perform alternate match on "pkg" against "pattern",
 * calling pmatch (recursively) to resolve any other patterns.
 * Return 1 on match, 0 otherwise
 */
static int
alternate_match(const char *pattern, const char *pkg)
{
	char   *sep;
	char    buf[MaxPathSize];
	char   *last;
	char   *alt;
	char   *cp;
	int     cnt;
	int     found;

	if ((sep = strchr(pattern, '{')) == (char *) NULL) {
		errx(EXIT_FAILURE, "alternate_match(): '{' expected in `%s'", pattern);
	}
	(void) strncpy(buf, pattern, (size_t) (sep - pattern));
	alt = &buf[sep - pattern];
	last = (char *) NULL;
	for (cnt = 0, cp = sep; *cp && last == (char *) NULL; cp++) {
		if (*cp == '{') {
			cnt++;
		} else if (*cp == '}' && --cnt == 0 && last == (char *) NULL) {
			last = cp + 1;
		}
	}
	if (cnt != 0) {
		errx(EXIT_FAILURE, "Malformed alternate `%s'", pattern);
	}
	for (found = 0, cp = sep + 1; *sep != '}'; cp = sep + 1) {
		for (cnt = 0, sep = cp; cnt > 0 || (cnt == 0 && *sep != '}' && *sep != ','); sep++) {
			if (*sep == '{') {
				cnt++;
			} else if (*sep == '}') {
				cnt--;
			}
		}
		(void) snprintf(alt, sizeof(buf) - (alt - buf), "%.*s%s", (int) (sep - cp), cp, last);
		if (pkg_match(buf, pkg) == 1) {
			found = 1;
		}
	}
	return found;
}

/*
 * Perform glob match on "pkg" against "pattern".
 * Return 1 on match, 0 otherwise
 */
static int
glob_match(const char *pattern, const char *pkg)
{
	return fnmatch(pattern, pkg, FNM_PERIOD) == 0;
}

/*
 * Perform simple match on "pkg" against "pattern". 
 * Return 1 on match, 0 otherwise
 */
static int
simple_match(const char *pattern, const char *pkg)
{
	return strcmp(pattern, pkg) == 0;
}

/*
 * Match pkg against pattern, return 1 if matching, 0 else
 */
int
pkg_match(const char *pattern, const char *pkg)
{
	if (strchr(pattern, '{') != (char *) NULL) {
		/* emulate csh-type alternates */
		return alternate_match(pattern, pkg);
	}
	if (strpbrk(pattern, "<>") != (char *) NULL) {
		int ret;

		/* perform relational dewey match on version number */
		ret = dewey_match(pattern, pkg);
		if (ret < 0)
			errx(EXIT_FAILURE, "dewey_match returned error");
		return ret;
	}
	if (strpbrk(pattern, "*?[]") != (char *) NULL) {
		/* glob match */
		return glob_match(pattern, pkg);
	}
	
	/* no alternate, dewey or glob match -> simple compare */
	return simple_match(pattern, pkg);
}
