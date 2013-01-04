/*	$NetBSD: kver.c,v 1.12 2013/01/04 06:00:48 apb Exp $	*/

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


#define KVER_VERSION_FMT "%s %s (LIBKVER) #0: Tue Jan 19 00:00:00 UTC 2038 root@localhost:/sys/arch/%s/compile/LIBKVER"

#define KVER_NOT_INITIALIZED_OSRELEASE	-2
#define KVER_INVALID_OSRELEASE	-1

/*
 * How to override the operating system name; e.g. "NetBSD".
 * Used by sysctl kern.ostype, uname -s, struct utsname.sysname
 */
#ifndef PATH_LIBKVER_OSTYPE
#define PATH_LIBKVER_OSTYPE "/libkver_ostype"
#endif
#ifndef VAR_LIBKVER_OSTYPE
#define VAR_LIBKVER_OSTYPE "LIBKVER_OSTYPE"
#endif

/*
 * How to override the operating system release level; e.g. "6.0_STABLE".
 * Used by sysctl kern.osrelease, uname -r, struct utsname.release
 *
 * This is also coverted to an integer, e.g. 601000000,
 * for use by sysctl.kern.osrevision.
 */
#ifndef PATH_LIBKVER_OSRELEASE
#define PATH_LIBKVER_OSRELEASE "/libkver_osrelease"
#endif
#ifndef VAR_LIBKVER_OSRELEASE
#define VAR_LIBKVER_OSRELEASE "LIBKVER_OSRELEASE"
#endif

/*
 * How to override the machine hardware platform, e.g. "i386".
 * Used by sysctl hw.machine, uname -m, struct utsname.machine.
 */
#ifndef PATH_LIBKVER_MACHINE
#define PATH_LIBKVER_MACHINE "/libkver_machine"
#endif
#ifndef VAR_LIBKVER_MACHINE
#define VAR_LIBKVER_MACHINE "LIBKVER_MACHINE"
#endif

/*
 * How to override the machine processor architecture, e.g. "i386".
 * Used by sysctl hw.machine_arch, uname -p.
 */
#ifndef PATH_LIBKVER_MACHINE_ARCH
#define PATH_LIBKVER_MACHINE_ARCH "/libkver_machine_arch"
#endif
#ifndef VAR_LIBKVER_MACHINE_ARCH
#define VAR_LIBKVER_MACHINE_ARCH "LIBKVER_MACHINE_ARCH"
#endif

static struct kver {
	char ostype[_SYS_NMLN];
	char osrelease[_SYS_NMLN];
	int osrevision;
	char version[_SYS_NMLN];
	char machine[_SYS_NMLN];
	char machine_arch[_SYS_NMLN];
}    kver = {
	.osrevision = KVER_NOT_INITIALIZED_OSRELEASE
};

static struct utsname real_utsname;

#define KVER_NOT_INITIALIZED	\
	(kver.osrevision == KVER_NOT_INITIALIZED_OSRELEASE)

#define KVER_BADLY_INITIALIZED	(kver.osrevision == KVER_INVALID_OSRELEASE)

#define SYSCTL_STRING(oldp, oldlenp, str)				\
	if (oldlenp) {							\
		size_t len = strlen(str) + 1;				\
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

/*
 * Initialise one element of struct kver.
 *
 * The result is based on getenv(envvarname), or readlink(linkname),
 * or defaultval.  If the provided defaultval is NULL, then the empty
 * string is used.
 *
 * Returns 1 if a non-default value was used, 0 if a default was used.
 */
static int
kver_init_var(char *dst, size_t dstlen, const char *envvar,
    const char *linkname, const char *defaultval)
{
	ssize_t len;
	char *v;

	v = getenv(envvar);
	if (v) {
		(void) strlcpy(dst, v, dstlen);
		return 1;
	}
	len = readlink(linkname, dst, dstlen);
	if (len > 0) {
		dst[len] = '\0';
		return 1;
	}
	if (defaultval) {
		(void) strlcpy(dst, defaultval, dstlen);
		return 0;
	}
	dst[0] = '\0';
	return 0;
}

static void
kver_initialize(void)
{
	char *v;
	int i;
	int nok = 0;
	char buf[PATH_MAX + 1];
	kver.osrevision = KVER_INVALID_OSRELEASE;	/* init done */

	if (_uname(&real_utsname) != 0) {
		warn("libkver: uname");
		return;
	}

	/*
	 * For each variable that can be overridden: try the
	 * environment variable, then try the symlink, or fall back
	 * to the unmodified (existing) value.
	 */
	nok += kver_init_var(kver.ostype, sizeof(kver.ostype),
	    VAR_LIBKVER_OSTYPE, PATH_LIBKVER_OSTYPE,
	    real_utsname.sysname);
	nok += kver_init_var(kver.osrelease, sizeof(kver.osrelease),
	    VAR_LIBKVER_OSRELEASE, PATH_LIBKVER_OSRELEASE,
	    real_utsname.release);
	nok += kver_init_var(kver.machine, sizeof(kver.machine),
	    VAR_LIBKVER_MACHINE, PATH_LIBKVER_MACHINE,
	    real_utsname.machine);
	nok += kver_init_var(kver.machine_arch, sizeof(kver.machine_arch),
	    VAR_LIBKVER_MACHINE_ARCH, PATH_LIBKVER_MACHINE_ARCH,
	    "");

	/*
	 * warning if the default was used for all variables.  no warning
	 * if at least one non-default value was used.
	 */
	if (nok == 0) {
		warnx("libkver: not configured");
		return;
	}

	/* machine_arch is not in struct utsname, so get default from sysctl */
	if (kver.machine_arch[0] == '\0') {
		int mib[] = { CTL_HW, HW_MACHINE_ARCH, 0 };
		size_t len = sizeof(kver.machine_arch);
		int err;

		err = _sysctl(mib, 2, kver.machine_arch, &len, NULL, 0);
		if (err < 0) {
			warn("libkver: sysctl hw.machine_arch");
			return;
		}
	}

	/* combine several strings to create kver.version */
	(void) snprintf(kver.version, sizeof(kver.version), KVER_VERSION_FMT,
	    kver.ostype, kver.osrelease, kver.machine);

	/*
	 * Convert string osrelease to integer osrevision.
	 * This must be the last thing we do, so that any failure
	 * resuls in kver.osrelease being set to KVER_INVALID_OSRELEASE.
	 */
	kver.osrevision = str2osrevision(kver.osrelease);
	if (kver.osrevision == KVER_INVALID_OSRELEASE) {
		warnx("libkver: cannot convert osrelease to osrevision: %s",
		    kver.osrelease);
	}

	return;
}

int
sysctl(SYSCTL_CONST int *name, u_int namelen, void *oldp, size_t * oldlenp,
    const void *newp, size_t newlen)
{
	int r = 0;

	_DIAGASSERT(name != NULL);

	if (newp != (void *) NULL)
		goto real;

	if (KVER_NOT_INITIALIZED)
		kver_initialize();

	if (KVER_BADLY_INITIALIZED || namelen != 2)
		goto real;

	switch (name[0]) {
	case CTL_KERN: {
		switch (name[1]) {
		case KERN_OSTYPE:
			SYSCTL_STRING(oldp, oldlenp, kver.ostype);
			return (r);
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
	case CTL_HW: {
		switch (name[1]) {
		case HW_MACHINE:
			SYSCTL_STRING(oldp, oldlenp, kver.machine);
			return (r);
		case HW_MACHINE_ARCH:
			SYSCTL_STRING(oldp, oldlenp, kver.machine_arch);
			return (r);
		}
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

	(void) strncpy(n->sysname, kver.ostype, _SYS_NMLN);
	(void) strncpy(n->nodename, real_utsname.nodename, _SYS_NMLN);
	(void) strncpy(n->release, kver.osrelease, _SYS_NMLN);
	(void) strncpy(n->version, kver.version, _SYS_NMLN);
	(void) strncpy(n->machine, kver.machine, _SYS_NMLN);
	return 0;
}
