dnl $NetBSD: configure.ac,v 1.42 2004/04/20 12:13:05 grant Exp $

dnl Process this file with autoconf to produce a configure script.
AC_PREREQ(2.52)
AC_INIT([libnbcompat], [20030916], [grant@NetBSD.org])
AC_CONFIG_HEADER(nbcompat/config.h)
AC_ARG_PROGRAM

AC_CANONICAL_HOST
CANONICAL_HOST=$host
AC_SUBST(CANONICAL_HOST)
AC_SUBST(INCLUDES)

# Checks for programs.
AC_PROG_MAKE_SET
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_RANLIB
AC_PROG_AWK
AC_CHECK_PROG(AR, ar, ar)

AUTOCONF=${AUTOCONF-"$srcdir/missing --run autoconf"}
AC_SUBST(AUTOCONF)
AUTOHEADER=${AUTOHEADER-"$srcdir/missing --run autoheader"}
AC_SUBST(AUTOHEADER)

dnl Checks for libraries
AC_CHECK_LIB(util, fparseln)

dnl Checks for header files.
AC_HEADER_STDC
AC_HEADER_TIME

AC_CHECK_HEADERS([arpa/nameser.h assert.h bind/bitypes.h dirent.h err.h \
	errno.h fcntl.h fts.h inttypes.h libutil.h limits.h \
	machine/endian.h memory.h ndir.h netdb.h netinet/in6_machtypes.h \
	paths.h pwd.h stdint.h stdlib.h stringlist.h strings.h \
	string.h sys/bitypes.h sys/byteorder.h sys/cdefs.h sys/dir.h \
	sys/endian.h sys/file.h sys/mkdev.h sys/ndir.h \
	sys/param.h sys/queue.h sys/time.h sys/ttycom.h \
	sys/stat.h sys/statfs.h sys/statvfs.h sys/vfs.h sys/types.h \
	sys/vfs.h termcap.h termios.h time.h tzfile.h unistd.h util.h \
	utmp.h])
AC_CHECK_HEADERS([sys/mount.h], , , [AC_INCLUDES_DEFAULT
#ifdef HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif
])

AC_CHECK_HEADERS([md5.h rmd160.h sha1.h])

pkg_use_nbcompat_md5=yes
AC_CHECK_HEADERS([md5.h], [
	AC_MSG_TRY_COMPILE([for MD5Init in md5.h], pkg_cv_have_md5init,
		[ #include <sys/types.h>
		  #include <md5.h> ],
		[ MD5_CTX *f; MD5Init(f); ],
		pkg_use_nbcompat_md5=no,
		pkg_use_nbcompat_md5=yes,
	)
])

if test $pkg_use_nbcompat_md5 = yes; then
        AC_DEFINE(HAVE_NBCOMPAT_MD5INIT)
        AH_TEMPLATE([HAVE_NBCOMPAT_MD5INIT], [
		Define to 1 if the `MD5Init' function is built into the
		library.
        ])
fi

pkg_use_nbcompat_getopt_long=yes
AC_CHECK_HEADERS([getopt.h], [
	AC_MSG_TRY_COMPILE([for struct option], pkg_cv_have_struct_option,
		[ #include <getopt.h> ], [ struct option X ],
		[ pkg_use_nbcompat_getopt_long=no ],
		[ pkg_use_nbcompat_getopt_long=yes ])
])
if test $pkg_use_nbcompat_getopt_long = yes; then
	AC_DEFINE(HAVE_NBCOMPAT_GETOPT_LONG)
	AH_TEMPLATE([HAVE_NBCOMPAT_GETOPT_LONG], [
		Define to 1 if the `getopt_long' function is built into the
		library.
	])
	AC_LIBOBJ(getopt_long)
fi

dnl Check that this vis.h has *vis()-related functions because Solaris'
dnl vis.h doesn't.  Also, only consider the header found if it defines
dnl all of the functions that we need.
dnl
pkg_use_nbcompat_vis=yes
AC_CHECK_HEADERS([vis.h], [
	AC_MSG_TRY_COMPILE([for VIS_WHITE in vis.h], pkg_cv_have_vis_white,
		[ #include <sys/types.h>
		  #include <vis.h> ], [ int X = VIS_WHITE ],
		[ pkg_use_nbcompat_vis=no], [ pkg_use_nbcompat_vis=yes ])
])

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C___ATTRIBUTE__
AC_TYPE_SIZE_T
AC_CHECK_TYPES([long long, int8_t, int16_t, int32_t, int64_t, u_int8_t, u_int16_t, u_int32_t, u_int64_t, uint8_t, uint16_t, uint32_t, uint64_t],[],[],
[#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif])
AC_CHECK_TYPES([fsid_t],[],[],
[#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif
#if HAVE_SYS_MOUNT_H
#include <sys/mount.h>
#endif
#if HAVE_SYS_VFS_H
#include <sys/vfs.h>
#endif])
AC_C_BIGENDIAN
AC_CHECK_SIZEOF(off_t, 0)

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_STRERROR_R
AC_FUNC_VPRINTF

AC_REPLACE_FUNCS([err fgetln fparseln fseeko getenv inet_ntop \
	inet_pton isblank lchflags lchmod lchown lutimes mkstemp mkdtemp \
	setprogname snprintf strdup strerror strlcat strlcpy \
	strmode strptime strsep strtoll timegm usleep utimes])

AC_CHECK_FUNCS([setgroupent setgrent setpassent setpwent])
AC_CHECK_FUNCS([bcopy bzero memset memcpy setlocale])
AC_CHECK_FUNCS([getmode setmode])
AC_CHECK_FUNCS([getmode setmode],
	[pkg_use_nbcompat_setmode=no],
	[pkg_use_nbcompat_setmode=yes; break])
pkg_use_nbcompat_setenv=no
AC_CHECK_FUNCS([setenv unsetenv], ,
	[pkg_use_nbcompat_setenv=yes])

if test $pkg_use_nbcompat_setmode = yes; then
	AC_LIBOBJ(setmode)
fi
if test $pkg_use_nbcompat_setenv = yes; then
	AC_LIBOBJ(setenv)
fi

AC_CHECK_FUNCS([gid_from_group group_from_gid pwcache_groupdb pwcache_userdb \
		uid_from_user user_from_uid])
AC_CHECK_FUNCS([gid_from_group group_from_gid pwcache_groupdb pwcache_userdb \
		uid_from_user user_from_uid],
	[pkg_use_nbcompat_pwcache=no],
	[pkg_use_nbcompat_pwcache=yes; break])

if test $pkg_use_nbcompat_pwcache = yes; then
	AC_LIBOBJ(pwcache)
fi

AC_CHECK_FUNC(fts_open, [:], [AC_LIBOBJ(__fts13)])

AC_CHECK_FUNC(MD5File, [:], [
	AC_LIBOBJ(md5c)
	AC_LIBOBJ(md5hl)
])
AC_CHECK_FUNC(RMD160File, [:], [
	AC_LIBOBJ(rmd160)
	AC_LIBOBJ(rmd160hl)
])
AC_CHECK_FUNC(SHA1File, [:], [
	AC_LIBOBJ(sha1)
	AC_LIBOBJ(sha1hl)
])

# handle Darwin 7 having a poll() compatibility function. be
# conservative, if we don't find one of poll.h or sys/poll.h, use our
# local poll() implementation.
pkg_use_nbcompat_poll=no
AC_CHECK_HEADERS([poll.h sys/poll.h])

if test $ac_cv_header_poll_h = no && test $ac_cv_header_sys_poll_h = no; then
	pkg_use_nbcompat_poll=yes
fi

if test $pkg_use_nbcompat_poll = yes; then
	AC_DEFINE(HAVE_NBCOMPAT_POLL, 1)
	AH_TEMPLATE([HAVE_NBCOMPAT_POLL], [
		Define to 1 if the `poll' function is built into the library.
	])
	AC_LIBOBJ(poll)
else
	AC_CHECK_FUNC(poll, [
        	AC_MSG_TRY_COMPILE([if poll() is implemented natively],
                pkg_cv_POLL_COMPAT,
		[ #if HAVE_POLL_H
		  #include <poll.h>
		  #endif
		  #if HAVE_SYS_POLL_H
		  #include <sys/poll.h>
		  #endif
		],
                [ #ifdef _POLL_EMUL_H_
		  #error "poll() is emulated"
	 	  #endif
		],
                [:], [AC_LIBOBJ(poll)])
])
fi

AC_CHECK_FUNCS([strunvis strvis strsvis])
AC_CHECK_FUNCS([strunvis strvis strsvis],
	[pkg_use_nbcompat_vis=no],
	[pkg_use_nbcompat_vis=yes; break])

if test $pkg_use_nbcompat_vis = yes; then
	AC_DEFINE(HAVE_NBCOMPAT_VIS)
	AH_TEMPLATE([HAVE_NBCOMPAT_VIS], [
		Define to 1 if the `vis' function is built into the library.
	])
	AC_LIBOBJ(vis)
	AC_LIBOBJ(unvis)
fi

AC_CHECK_FUNCS([getpassphrase getpgrp memmove select])

AC_CHECK_FUNC(getpgrp, [AC_FUNC_GETPGRP])

AC_CHECK_FUNC(sl_init, [
	AC_MSG_TRY_COMPILE([if sl_add() returns int],
		pkg_cv_INT_SL_ADD,
		[ #include <stringlist.h> ],
		[ int f = sl_add((StringList *)0, "foo") ],
		[:] , [AC_LIBOBJ(sl_init)])
])

dnl Solaris 2.7, 2.8 and UnixWare 7 have statfs(2), but it is deprecated,
dnl and has a different interface from NetBSD's statfs.
dnl
pkg_use_nbcompat_statfs=yes
AC_CHECK_FUNC(statfs, [
	case $host_os in
	irix*|sunos*|solaris*|*UnixWare*)
		AC_CHECK_FUNC(statvfs, [:], [
			AC_MSG_ERROR(statfs can't be implemented correctly)
		])
		;;
	*)
		pkg_use_nbcompat_statfs=no
		;;
	esac
])

if test $pkg_use_nbcompat_statfs = yes; then
	AC_DEFINE(HAVE_NBCOMPAT_STATFS, 1)
	AH_TEMPLATE([HAVE_NBCOMPAT_STATFS], [
		Define to 1 if the `statfs' function is built into the library.
	])
	AC_LIBOBJ(statfs)
	AC_CHECK_MEMBERS([struct statvfs.f_basetype],[],[],[#include <sys/statvfs.h>])
fi

if test $ac_cv_type_long_long = yes; then

dnl		We assume that if sprintf() supports %lld or %qd,
dnl		then all of *printf() does. If not, disable long long
dnl		support because we don't know how to display it.

	AC_MSG_CHECKING(*printf() support for %lld)
	can_printf_longlong=no
	AC_TRY_RUN([
		#include <stdio.h>
		int main() {
			char buf[100];
			sprintf(buf, "%lld", 4294967300LL);
			return (strcmp(buf, "4294967300"));
		}
	], [
		AC_MSG_RESULT(yes)
		can_printf_longlong=yes
	], [
		AC_MSG_RESULT(no)
	], [ : ])

	if test $can_printf_longlong != yes; then
		AC_MSG_CHECKING(*printf() support for %qd)
		AC_TRY_RUN([
			#include <stdio.h>
			int main() {
				char buf[100];
				sprintf(buf, "%qd", 4294967300LL);
				return (strcmp(buf, "4294967300"));
			}
		], [
			AC_MSG_RESULT(yes)
			can_printf_longlong=yes
			AC_DEFINE(HAVE_PRINTF_QD, 1)
			AH_TEMPLATE([HAVE_PRINTF_QD], [
				Define to 1 if *printf() uses %qd to print
				`long long' (otherwise uses %lld).
			])
		], [
			AC_MSG_RESULT(no)
		], [ : ])
	fi

	if test $can_printf_longlong = yes; then
		AC_DEFINE(HAVE_WORKING_LONG_LONG, 1)
		AH_TEMPLATE([HAVE_WORKING_LONG_LONG], [
			Define to 1 if `long long' is supported and
			sizeof(off_t) >= 8.
		])
		AC_REPLACE_FUNCS(strtoll)
	fi

fi

AC_MSG_TRY_COMPILE(for optarg declaration, ftp_cv_HAVE_OPTARG_D, [
	#include <stdlib.h>
	#include <unistd.h>
], [ char *X = optarg ], [:], [
	AC_DEFINE(HAVE_OPTARG_D, 1)
	AH_TEMPLATE([HAVE_OPTARG_D], [
		Define to 1 if optarg is declared in <stdlib.h> or <unistd.h>
	])
])

AC_MSG_TRY_COMPILE(for optind declaration, ftp_cv_HAVE_OPTIND_D, [
	#include <stdlib.h>
	#include <unistd.h>
], [ int X = optind ], [:] [
	AC_DEFINE(HAVE_OPTIND_D, 1)
	AH_TEMPLATE([HAVE_OPTIND_D], [
		Define to 1 if optind is declared in <stdlib.h> or <unistd.h>
	])
])

AH_BOTTOM([
/* NBCOMPAT template section follows. */

#ifndef HAVE___ATTRIBUTE__
# define __attribute__(x)
#endif

#if HAVE_SYS_CDEFS_H
#include <sys/cdefs.h>
#endif

#ifndef __IDSTRING
# define __IDSTRING(name,string) \
       static const char name[] __attribute__((__unused__)) = string
#endif

#ifndef  __RCSID
# define __RCSID(_s)     __IDSTRING(rcsid,_s)
#endif

#ifndef __COPYRIGHT
# define __COPYRIGHT(_s) __IDSTRING(copyright,_s)
#endif

#ifndef __P
# if defined(__STDC__) || defined(__cplusplus)
#  define __P(protos)     protos          /* full-blown ANSI C */
# else
#  define __P(protos)     ()              /* traditional C preprocessor */
# endif
#endif

#ifndef __CONCAT
#  if defined(__STDC__) || defined(__cplusplus)
#  define __CONCAT(x,y)   x ## y
# else
#  define __CONCAT(x,y)   x/**/y
# endif
#endif

#ifndef __BEGIN_DECLS
# if defined(__cplusplus)
#  define __BEGIN_DECLS   extern "C" {
# else
#  define __BEGIN_DECLS
# endif
#endif

#ifndef __END_DECLS
# if defined(__cplusplus)
#  define __END_DECLS     };
# else
#  define __END_DECLS
# endif
#endif

#if HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif

#if HAVE_SYS_ENDIAN_H
#include <sys/endian.h>
#endif

#if HAVE_MACHINE_ENDIAN_H
#include <machine/endian.h>
#endif

#if HAVE_SYS_BYTEORDER_H
#include <sys/byteorder.h>
#endif

#if HAVE_LIMITS_H
#include <limits.h>
#endif

#ifndef LITTLE_ENDIAN
# define LITTLE_ENDIAN 1234
#endif

#ifndef BIG_ENDIAN
# define BIG_ENDIAN    4321
#endif

#ifndef UINT_MAX
# define UINT_MAX 4294967295U
#endif

#ifndef BYTE_ORDER
# if defined(_BIG_ENDIAN)
#  define BYTE_ORDER BIG_ENDIAN
# elif defined(_LITTE_ENDIAN)
#  define BYTE_ORDER LITTLE_ENDIAN
# elif defined(WORDS_BIGENDIAN)
#  define BYTE_ORDER BIG_ENDIAN
# else 
#  define BYTE_ORDER LITTLE_ENDIAN
# endif
#endif

#if defined(HAVE_MEMSET)
# define MEMSET_BZERO(p,l)	memset((p), 0, (l))
#elif defined(HAVE_BZERO)
# define MEMSET_BZERO(p,l)	bzero((p), (l))
#else
# error You need either memset or bzero
#endif

#if defined(HAVE_MEMCPY)
# define MEMCPY_BCOPY(d,s,l)	memcpy((d), (s), (l))
#elif defined(HAVE_BCOPY)
# define MEMCPY_BCOPY(d,s,l)	bcopy((s), (d), (l))
#else
# error You need either memcpy or bcopy
#endif
])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
