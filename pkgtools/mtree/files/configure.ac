dnl Process this file with autoconf to produce a configure script.
AC_PREREQ(2.52)
AC_INIT([mtree], [20030331], [grant@NetBSD.org])
AC_CONFIG_SRCDIR([mtree.c])
AC_CONFIG_HEADER(config.h)
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
AC_CHECK_PROG(AR, ar, ar)

AUTOCONF=${AUTOCONF-"$srcdir/missing --run autoconf"}
AC_SUBST(AUTOCONF)
AUTOHEADER=${AUTOHEADER-"$srcdir/missing --run autoheader"}
AC_SUBST(AUTOHEADER)

dnl Checks for libraries.
dnl
AC_CHECK_LIB(util, fparseln)

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([sys/endian.h sys/file.h sys/mkdev.h sys/param.h])

AC_CHECK_HEADERS([assert.h arpa/nameser.h dirent.h err.h errno.h fcntl.h \
		fts.h libutil.h locale.h machine/endian.h param.h paths.h \
		poll.h regex.h stringlist.h sys/byteorder.h sys/poll.h \
		termcap.h unistd.h util.h vis.h limits.h])

AC_CHECK_HEADERS([bind/bitypes.h inttypes.h sys/bitypes.h sys/cdefs.h \
		sys/endian.h sys/mkdev.h sys/mount.h sys/queue.h \
		sys/stat.h sys/statvfs.h sys/vfs.h sys/types.h \
		sys/byteorder.h])


dnl Checks for typedefs, structures, and compiler characteristics.
AC_C___ATTRIBUTE__
AC_TYPE_SIZE_T
AC_CHECK_TYPES([long long, int8_t, int16_t, int32_t, int64_t, u_int8_t, u_int16_t, u_int32_t, u_int64_t, uint8_t, uint16_t, uint32_t, uint64_t],[],[],
[#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#ifdef HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#ifdef HAVE_SYS_BITYPES_H
#include <sys/bitypes.h>
#endif])
AC_C_BIGENDIAN
AC_CHECK_SIZEOF(off_t, 0)

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_STRERROR_R
AC_FUNC_VPRINTF

AC_REPLACE_FUNCS([err fgetln fseeko getenv glob inet_ntop \
		inet_pton lchflags lchmod lchown lutimes mkstemp setenv \
		setprogname sl_init snprintf strdup strerror strlcat \
		strlcpy strptime strsep strtoll timegm usleep])

AC_CHECK_FUNCS([MD5File RMD160File SHA1File])
AC_CHECK_FUNCS([setgroupent setgrent setpassent setpwent])
AC_CHECK_FUNCS([bcopy bzero memset memcpy setlocale])
AC_CHECK_FUNCS([statfs statvfs])
AC_CHECK_FUNCS([gid_from_group group_from_gid pwcache_groupdb pwcache_userdb \
		uid_from_user user_from_uid])

AC_CHECK_FUNCS([strunvis strvis strsvis])

AC_CHECK_FUNCS([getpassphrase getpgrp memmove poll select])

if test $ac_cv_func_getpgrp = yes; then
	AC_FUNC_GETPGRP
fi
if test $ac_cv_lib_util_fparseln != yes; then
	AC_REPLACE_FUNCS([fparseln])
fi

if test $ac_cv_type_long_long = yes -a $ac_cv_sizeof_off_t -ge 8; then

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
		], [
			AC_MSG_RESULT(no)
		], [ : ])
	fi

	if test $can_printf_longlong = yes; then
		AC_DEFINE(HAVE_QUAD_SUPPORT, 1)
		AC_REPLACE_FUNCS(strtoll)
	fi

fi

if test $ac_cv_func_sl_init = yes; then
	AC_MSG_TRY_COMPILE(if sl_add() returns int, pkg_cv_INT_SL_ADD, [
	#include <stringlist.h> ], [ int f = sl_add((StringList *)0, "foo") ],
	[:] , [AC_LIBOBJ="$AC_LIBOBJ sl_init.o"])
fi

if test $ac_cv_header_vis_h = yes; then
	AC_MSG_TRY_COMPILE(for VIS_WHITE in vis.h,
			    pkg_cv_have_vis_white, [
	#include <sys/types.h>
	#include <vis.h> ], [ int X = VIS_WHITE ], [:],
	ac_cv_header_vis_h=no )
fi

AH_BOTTOM([

#ifndef HAVE___ATTRIBUTE__
# define __attribute__(x)
#endif

#ifdef HAVE_SYS_CDEFS_H
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

#ifdef HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif

#ifdef HAVE_SYS_ENDIAN_H
#include <sys/endian.h>
#endif

#ifdef HAVE_MACHINE_ENDIAN_H
#include <machine/endian.h>
#endif

#ifdef HAVE_SYS_BYTEORDER_H
#include <sys/byteorder.h>
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
#define MEMSET_BZERO(p,l)	memset((p), 0, (l))
#else
# if defined(HAVE_BZERO)
#define MEMSET_BZERO(p,l)	bzero((p), (l))
# else
#error You need either memset or bzero
# endif
#endif

#if defined(HAVE_MEMCPY)
#define MEMCPY_BCOPY(d,s,l)	memcpy((d), (s), (l))
#else
# if defined(HAVE_BCOPY)
#define MEMCPY_BCOPY(d,s,l)	bcopy((s), (d), (l))
# else
#error You need either memcpy or bcopy
# endif
#endif
])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
