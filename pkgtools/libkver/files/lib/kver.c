/*	$NetBSD: kver.c,v 1.10 2011/11/22 18:13:09 joerg Exp $	*/

#define sysctl _sysctl
#define uname _uname

#include <sys/types.h>
#include <sys/param.h>
#include <sys/sysctl.h>
#include <sys/utsname.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <err.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

#undef sysctl
#undef uname

#define KVER_VERSION_FMT "NetBSD %s (LIBKVER) #0: Tue Jan 19 00:00:00 UTC 2038 root@localhost:/sys/arch/%s/compile/LIBKVER"

#define KVER_NOT_INITIALIZED_OSRELEASE	-2
#define KVER_INVALID_OSRELEASE	-1

#ifndef PATH_LIBKVER_OSRELEASE
#define PATH_LIBKVER_OSRELEASE "/libkver_osrelease"
#endif
#ifndef VAR_LIBKVER_OSRELEASE
#define VAR_LIBKVER_OSRELEASE "LIBKVER_OSRELEASE"
#endif

static struct kver {
	char osrelease[_SYS_NMLN];
	int osrevision;
	char version[_SYS_NMLN];
}    kver = {
	"", KVER_NOT_INITIALIZED_OSRELEASE, ""
};

static struct utsname real_utsname;

#define KVER_NOT_INITIALIZED	\
	(kver.osrevision == KVER_NOT_INITIALIZED_OSRELEASE)

#define KVER_BADLY_INITIALIZED	(kver.osrevision == KVER_INVALID_OSRELEASE)

#define SYSCTL_STRING(oldp, oldlenp, str)				\
	if (oldlenp) {							\
		len = strlen(str) + 1;					\
		if (!oldp)						\
			*oldlenp = len;					\
		else {							\
			if (*oldlenp < len) {				\
				r = ENOMEM;				\
				len = *oldlenp;				\
			} else						\
				*oldlenp = len;				\
			(void) strncpy(oldp, str, len);			\
		}							\
	}

#if __NetBSD_Version__ >= 399001600
#define SYSCTL_CONST	const
#else
#define SYSCTL_CONST
#endif

static int
str2osrevision(char *s)
{
	char c;
	int n, r = 0;

	if (s == NULL || *s == 0)
		return KVER_INVALID_OSRELEASE;

	if (!isdigit(*s))
		return KVER_INVALID_OSRELEASE;

	/* first digit: major */
	for (n = 0; isdigit(*s); s++) {
		n = (n * 10) + (*s - '0');
	}
	if (*s == 0 || *s != '.')
		return KVER_INVALID_OSRELEASE;
	r += (n * 100000000);

	/* second digit: minor */
	for (s++, n = 0; isdigit(*s); s++) {
		n = (n * 10) + (*s - '0');
	}
	r += (n * 1000000);

	/* nothing more, return */
	if (*s == 0)
		return r;

	/* optional third digit: patchlevel */
	if (*s == '.') {
		for (s++, n = 0; isdigit(*s); s++) {
			n = (n * 10) + (*s - '0');
		}
		r += (n * 100);
	}
	/* nothing more, return */
	if (*s == 0)
		return r;
	/* or optional underscore followed by release status */
	if (*s == '_')
		/* ignore the trailing label */
		return r;
	/* or optional letters: release */
	n = 0;
	c = 'Z';
	while (*s >= 'A' && *s <= 'Z') {
		if (c != 'Z' && *s != 0)
			break;
		c = *s;
		n += *s++ - '@';
	}
	if (n > 99)
		return KVER_INVALID_OSRELEASE;
	if (*s == 0)
		return r + (n * 10000);

	/* return on error if we end up here */
	return KVER_INVALID_OSRELEASE;
}

static void
kver_initialize(void)
{
	char *v;
	int i;
	kver.osrevision = KVER_INVALID_OSRELEASE;	/* init done */
	v = getenv(VAR_LIBKVER_OSRELEASE);
	if (v == NULL) {
		char b[MAXPATHLEN + 1];
		i = readlink(PATH_LIBKVER_OSRELEASE, b, sizeof b - 1);
		if (i <= 0) {
			v = NULL;
		} else {
			b[i] = '\0';
			v = b;
		}
	}
	if (v == NULL) {
		warnx("libkver: not configured");
		return;
	}
	if (_uname(&real_utsname) != 0) {
		warn("libkver: uname");
		return;
	}
	kver.osrevision = str2osrevision(v);
	if (kver.osrevision == KVER_INVALID_OSRELEASE) {
		warnx("libkver: invalid version: %s", v);
		return;
	}
	(void) strncpy(kver.osrelease, v, _SYS_NMLN);
	kver.osrelease[_SYS_NMLN - 1] = '\0';
	(void) snprintf(kver.version, _SYS_NMLN, KVER_VERSION_FMT,
	    kver.osrelease, real_utsname.machine);
	return;
}

int
sysctl(SYSCTL_CONST int *name, u_int namelen, void *oldp, size_t * oldlenp,
    const void *newp, size_t newlen)
{
	_DIAGASSERT(name != NULL);

	if (newp != (void *) NULL)
		goto real;

	if (KVER_NOT_INITIALIZED)
		kver_initialize();

	if (KVER_BADLY_INITIALIZED || namelen != 2)
		goto real;

	if (name[0] == CTL_KERN) {
		size_t len;
		int r = 0;
		switch (name[1]) {
		case KERN_OSRELEASE:
			SYSCTL_STRING(oldp, oldlenp, kver.osrelease);
			return (r);
		case KERN_OSREV:
			if (oldlenp) {
				if (!oldp)
					*oldlenp = sizeof(int);
				else {
					if (*oldlenp < sizeof(int))
						return (ENOMEM);
					*oldlenp = sizeof(int);
					*((int *) oldp) = kver.osrevision;
				}
			}
			return (r);
		case KERN_VERSION:
			SYSCTL_STRING(oldp, oldlenp, kver.version);
			return (r);
		}
	}
real:	return (_sysctl(name, namelen, oldp, oldlenp, newp, newlen));
}

int
uname(struct utsname * n)
{
	if (KVER_NOT_INITIALIZED)
		kver_initialize();

	if (KVER_BADLY_INITIALIZED)
		return _uname(n);

	(void) strncpy(n->sysname, real_utsname.sysname, _SYS_NMLN);
	(void) strncpy(n->nodename, real_utsname.nodename, _SYS_NMLN);
	(void) strncpy(n->release, kver.osrelease, _SYS_NMLN);
	(void) strncpy(n->version, kver.version, _SYS_NMLN);
	(void) strncpy(n->machine, real_utsname.machine, _SYS_NMLN);
	return 0;
}
