/*	$NetBSD: kver.c,v 1.1.1.1 2003/07/11 14:50:37 seb Exp $	*/

#include <sys/types.h>
#include <sys/param.h>
#include <sys/sysctl.h>
#include <sys/utsname.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

#define KVER_VERSION_FMT "NetBSD %.6s (GENERIC) #0: %.40s  root@localhost:/sys/arch/%.20s/compile/GENERIC %.20s"

/* _KVER_DATE is not really the real release date but the
   date of src/sys/sys/param.h's revision tagged for the release */

#if   _KVER_OSREVISION == 105000000
#  define _KVER_OSRELEASE "1.5"
#  define _KVER_DATE "Wed Dec  6 00:00:00 UTC 2000"
#elif _KVER_OSREVISION == 105000100
#  define _KVER_OSRELEASE "1.5.1"
#  define _KVER_DATE "Wed Jul 11 00:00:00 UTC 2001"
#elif _KVER_OSREVISION == 105000200
#  define _KVER_OSRELEASE "1.5.2"
#  define _KVER_DATE "Thu Sep 13 00:00:00 UTC 2001"
#elif _KVER_OSREVISION == 105000300
#  define _KVER_OSRELEASE "1.5.3"
#  define _KVER_DATE "Mon Jul 22 00:00:00 UTC 2002"
#elif _KVER_OSREVISION == 106000000
#  define _KVER_OSRELEASE "1.6"
#  define _KVER_DATE "Sat Sep 14 00:00:00 UTC 2002"
#elif _KVER_OSREVISION == 106000100
#  define _KVER_OSRELEASE "1.6.1";
#  define _KVER_DATE "Mon Apr 21 00:00:00 UTC 2003"
#else
#error You must define _KVER_OSREVISION
#endif

static char *kver_osrelease = _KVER_OSRELEASE;
static char *kver_date = _KVER_DATE;
static int kver_osrevision = _KVER_OSREVISION;

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

/* 6  chars for osrelease */
/* 40 chars for the date string */
/* 40 chars for 2 utsname.machine */
#define KVER_VERSION_LEN	(sizeof(KVER_VERSION_FMT) + 6 + 40 + 40 + 1)
static char kver_version[KVER_VERSION_LEN] = "";
static struct utsname real_utsname;

static void
kver_init(void)
{
	if (_uname(&real_utsname) != 0)
		return;
	snprintf(kver_version, KVER_VERSION_LEN, KVER_VERSION_FMT,
		kver_osrelease,
		kver_date,
		real_utsname.machine,
		real_utsname.machine);
}

int
sysctl(int *name, u_int namelen, void *oldp, size_t * oldlenp, const void *newp,
    size_t newlen)
{
	_DIAGASSERT(name != NULL);

	if (newp != (void *) NULL)
		goto real;

	if (namelen != 2) {
		errno = EINVAL;
		return (-1);
	}

	if (*kver_version == '\0') {
		kver_init();
		if (*kver_version == '\0')
			return(-1);
	}

	if (name[0] == CTL_KERN) {
		size_t len;
		int r = 0;
		switch (name[1]) {
		case KERN_OSRELEASE:
			SYSCTL_STRING(oldp, oldlenp, kver_osrelease);
			return (r);
		case KERN_OSREV:
			if (oldlenp) {
				if (!oldp)
					*oldlenp = sizeof(int);
				else {
					if (*oldlenp < sizeof(int))
						return (ENOMEM);
					*oldlenp = sizeof(int);
					*((int *) oldp) = kver_osrevision;
				}
			}
			return (r);
		case KERN_VERSION:
			SYSCTL_STRING(oldp, oldlenp, kver_version);
			return (r);
		}
	}
real:	return (_sysctl(name, namelen, oldp, oldlenp, newp, newlen));
}


int
uname(struct utsname * n)
{
	if (*kver_version == '\0') {
		kver_init();
		if (*kver_version == '\0')
			return(-1);
	}
	(void) strncpy(n->sysname, real_utsname.sysname, _SYS_NMLN);
	(void) strncpy(n->nodename, real_utsname.nodename, _SYS_NMLN);
	(void) strncpy(n->release, kver_osrelease, _SYS_NMLN);
	(void) strncpy(n->version, kver_version, _SYS_NMLN);
	(void) strncpy(n->machine, real_utsname.machine, _SYS_NMLN);
	return 0;
}
