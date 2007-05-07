dnl $NetBSD: configure.ac,v 1.53 2007/05/07 16:38:47 joerg Exp $

dnl Process this file with autoconf to produce a configure script.
AC_PREREQ(2.52)
AC_INIT([libnbcompat], [20040911], [grant@NetBSD.org])
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

dnl Used by bits.c to check for sizes of integer types
AC_CHECK_HEADERS([inttypes.h sys/types.h sys/bitypes.h bind/bitypes.h \
	netinet/in6_machtypes.h])

AC_CHECK_HEADERS([alloca.h assert.h ctype.h dirent.h err.h errno.h fcntl.h \
	fnmatch.h fts.h grp.h libutil.h limits.h machine/endian.h ndir.h \
	paths.h pwd.h signal.h stdarg.h stddef.h stdint.h stdio.h stdlib.h \
	string.h sys/byteorder.h sys/cdefs.h sys/dir.h sys/endian.h \
	sys/file.h sys/mkdev.h sys/ndir.h sys/param.h sys/stat.h \
	sys/statfs.h sys/statvfs.h sys/time.h sys/ttycom.h sys/types.h \
	sys/uio.h sys/vfs.h termcap.h time.h tzfile.h unistd.h \
	util.h utime.h
])
AC_CHECK_HEADERS([sys/mount.h], [:], [:], [
	AC_INCLUDES_DEFAULT
	#ifdef HAVE_SYS_PARAM_H
	#include <sys/param.h>
	#endif
])

dnl Always use our own glob().
AC_CHECK_HEADERS([glob.h])
AC_DEFINE(HAVE_NBCOMPAT_GLOB)
AH_TEMPLATE([HAVE_NBCOMPAT_GLOB], [
	Define to 1 if the `glob' function is built into the library.
])
AC_LIBOBJ(glob)

dnl Always use our own queue(3) implementation.
AC_CHECK_HEADERS([sys/queue.h])
AC_DEFINE(HAVE_NBCOMPAT_QUEUE)
AH_TEMPLATE([HAVE_NBCOMPAT_QUEUE], [
	Define to 1 if the `queue' macros are supplied by the library.
])

AC_CHECK_HEADERS([regex.h])
AC_CHECK_FUNC(regexec, [:], [
	AC_DEFINE(HAVE_NBCOMPAT_REGEX)
	AH_TEMPLATE([HAVE_NBCOMPAT_REGEX], [
		Define to 1 if the `regex' functions are built into the
		library.
        ])
	AC_LIBOBJ(regcomp)
	AC_LIBOBJ(regerror)
	AC_LIBOBJ(regexec)
	AC_LIBOBJ(regfree)
])

AC_CHECK_HEADERS([md5.h], [
	AC_MSG_TRY_COMPILE([for MD5Init in md5.h], pkg_cv_have_md5init, [
		#include <sys/types.h>
		#include <md5.h>
	], [
		MD5_CTX *f;
		MD5Init(f);
	], [:], [
        	AC_DEFINE(HAVE_NBCOMPAT_MD5INIT)
		AH_TEMPLATE([HAVE_NBCOMPAT_MD5INIT], [
			Define to 1 if the `MD5Init' function is built into
			the library.
        	])
	])
])

AC_CHECK_HEADERS([md5.h rmd160.h sha1.h sha2.h])
AC_CHECK_FUNC(MD5File, [:], [
       	AC_DEFINE(HAVE_NBCOMPAT_MD5)
	AH_TEMPLATE([HAVE_NBCOMPAT_MD5], [
		Define to 1 if the `MD5*' functions are built into the
		library.
        ])
	AC_LIBOBJ(md5c)
	AC_LIBOBJ(md5hl)
])
AC_CHECK_FUNC(RMD160File, [:], [
       	AC_DEFINE(HAVE_NBCOMPAT_RMD160)
	AH_TEMPLATE([HAVE_NBCOMPAT_RMD160], [
		Define to 1 if the `RMD160*' functions are built into the
		library.
        ])
	AC_LIBOBJ(rmd160)
	AC_LIBOBJ(rmd160hl)
])
AC_CHECK_FUNC(SHA1File, [:], [
       	AC_DEFINE(HAVE_NBCOMPAT_SHA1)
	AH_TEMPLATE([HAVE_NBCOMPAT_SHA1], [
		Define to 1 if the `SHA1*' functions are built into the
		library.
        ])
	AC_LIBOBJ(sha1)
	AC_LIBOBJ(sha1hl)
])

AC_CHECK_FUNC(SHA2File, [:], [
       	AC_DEFINE(HAVE_NBCOMPAT_SHA2)
	AH_TEMPLATE([HAVE_NBCOMPAT_SHA2], [
		Define to 1 if the `SHA2*' functions are built into the
		library.
        ])
	AC_LIBOBJ(sha2)
	AC_LIBOBJ(sha2hl)
])

pkg_use_nbcompat_getopt_long=yes
AC_CHECK_HEADERS([getopt.h], [
	AC_MSG_TRY_COMPILE([for struct option], pkg_cv_have_struct_option,
		[ #include <getopt.h> ], [ struct option X; ],
		[pkg_use_nbcompat_getopt_long=no],
		[pkg_use_nbcompat_getopt_long=yes])
])

if test $pkg_use_nbcompat_getopt_long = yes; then
	AC_DEFINE(HAVE_NBCOMPAT_GETOPT_LONG)
	AH_TEMPLATE([HAVE_NBCOMPAT_GETOPT_LONG], [
		Define to 1 if the `getopt_long' function is
		built into the library.
	])
	AC_LIBOBJ(getopt_long)
fi

dnl Check that this vis.h has *vis()-related functions because Solaris'
dnl vis.h doesn't.  Also, only consider the header found if it defines
dnl all of the functions that we need.
dnl
pkg_use_nbcompat_vis=yes
AC_CHECK_HEADERS([vis.h], [
	AC_MSG_TRY_COMPILE([for VIS_WHITE in vis.h], pkg_cv_have_vis_white, [
		#include <sys/types.h>
		#include <vis.h>
	], [ int X = VIS_WHITE; ], [
		AC_CHECK_FUNCS([strunvis strvis strsvis svis unvis vis])
		AC_CHECK_FUNCS([strunvis strvis strsvis svis unvis vis],
			[pkg_use_nbcompat_vis=no],
			[pkg_use_nbcompat_vis=yes; break])
	])
])

if test $pkg_use_nbcompat_vis = yes; then
	AC_DEFINE(HAVE_NBCOMPAT_VIS)
	AH_TEMPLATE([HAVE_NBCOMPAT_VIS], [
		Define to 1 if the `vis' function is built into the library.
	])
	AC_LIBOBJ(vis)
	AC_LIBOBJ(unvis)
fi

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C___ATTRIBUTE__
AC_TYPE_SIZE_T
AC_CHECK_TYPES([long long, long double, int8_t, int16_t, int32_t, int64_t, u_int8_t, u_int16_t, u_int32_t, u_int64_t, uint8_t, uint16_t, uint32_t, uint64_t],[],[],
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

AC_REPLACE_FUNCS([err fgetln fnmatch fparseln getenv isblank \
	lchflags lchmod lchown lutimes mkdtemp mkstemp setenv setgroupent \
	setpassent setprogname snprintf statvfs strdup strerror strlcat \
	strlcpy strmode strsep strtoll unsetenv usleep utimes warn
])

AC_CHECK_FUNCS([getenv setenv unsetenv], [:], [
	AC_LIBOBJ(findenv)
	break
])

AC_CHECK_FUNCS([mkdtemp mkstemp], [:], [
	AC_LIBOBJ(gettemp)
	break
])

AC_CHECK_FUNCS([bcopy bzero memset memcpy setlocale])
AC_CHECK_FUNCS([getmode setmode])
AC_CHECK_FUNCS([getmode setmode], [:], [
	AC_LIBOBJ(setmode)
	break
])

AC_CHECK_FUNCS([gid_from_group group_from_gid pwcache_groupdb \
	pwcache_userdb uid_from_user user_from_uid \
])
AC_CHECK_FUNCS([gid_from_group group_from_gid pwcache_groupdb \
	pwcache_userdb uid_from_user user_from_uid \
], [:], [
	AC_LIBOBJ(pwcache)
	break
])

AC_CHECK_FUNC(fts_open, [:], [
	AC_DEFINE(HAVE_NBCOMPAT_FTS, 1)
	AH_TEMPLATE([HAVE_NBCOMPAT_FTS], [
		Define to 1 if the `fts_*' functions are built into the
		library.
	])
	AC_LIBOBJ(fts)
])

# Handle Darwin 7 having a poll() compatibility function.  Be
# conservative -- if we don't find one of <poll.h> or <sys/poll.h>, then
# use our own poll() implementation.
#
pkg_cv_have_poll_h=no
AC_CHECK_HEADERS([poll.h sys/poll.h])
AC_CHECK_HEADERS([poll.h sys/poll.h], [pkg_cv_have_poll_h=yes])

pkg_use_nbcompat_poll=yes
if test $pkg_cv_have_poll_h = yes; then
	pkg_use_nbcompat_poll=no
fi

if test $pkg_cv_have_poll_h = yes -o test $pkg_cv_have_sys_poll_h = yes; then
	AC_CHECK_FUNC(poll, [
        	AC_MSG_TRY_COMPILE([if poll() is implemented natively],
                pkg_cv_native_poll,
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
                [pkg_use_nbcompat_poll=no],
		[pkg_use_nbcompat_poll=yes])
	])
fi

if test $pkg_use_nbcompat_poll = yes; then
	AC_DEFINE(HAVE_NBCOMPAT_POLL, 1)
	AH_TEMPLATE([HAVE_NBCOMPAT_POLL], [
		Define to 1 if the `poll' function is built into the library.
	])
	AC_LIBOBJ(poll)
fi

AC_CHECK_FUNCS([getpassphrase getpgrp memmove select])

AC_CHECK_FUNC(getpgrp, [AC_FUNC_GETPGRP])

AC_CHECK_MEMBERS([struct statfs.f_fsize], [:], [:],
	[ #include <sys/statfs.h> ])
AC_CHECK_MEMBERS([struct statfs.f_iosize], [:], [:],
	[ #include <sys/statfs.h> ])
AC_CHECK_MEMBERS([struct dirent.d_namlen], [:], [:],
	[ #include <sys/types.h>
	  #if HAVE_DIRENT_H
	  # include <dirent.h>
	  #else
	  # define dirent direct
	  # if HAVE_SYS_NDIR_H
	  #  include <sys/ndir.h>
	  # endif
	  # if HAVE_SYS_DIR_H
	  #  include <sys/dir.h>
	  # endif
	  # if HAVE_NDIR_H
	  #  include <ndir.h>
	  # endif
	  #endif ])

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
	], [:])

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
		], [:])
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

AC_CHECK_DECLS([optind, optreset], [:], [:], [
	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
])

AH_BOTTOM([
/* NBCOMPAT template section follows. */

#ifndef HAVE___ATTRIBUTE__
# define __attribute__(x)
#endif
])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
