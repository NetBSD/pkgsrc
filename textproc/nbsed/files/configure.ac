dnl $Id: configure.ac,v 1.12 2024/03/31 13:31:41 js Exp $
dnl Process this file with autoconf to produce a configure script.
AC_PREREQ([2.72])
AC_INIT([sed],[20040821],[agc@NetBSD.org])
AC_CONFIG_SRCDIR([main.c])
AC_CONFIG_HEADERS([config.h])
AC_ARG_PROGRAM

AC_CANONICAL_HOST
CANONICAL_HOST=$host
AC_SUBST(CANONICAL_HOST)

dnl Checks for programs.
AC_PROG_MAKE_SET
AC_PROG_AWK
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S

AUTOCONF=${AUTOCONF-"$srcdir/missing --run autoconf"}
AC_SUBST(AUTOCONF)
AUTOHEADER=${AUTOHEADER-"$srcdir/missing --run autoheader"}
AC_SUBST(AUTOHEADER)

dnl Checks for header files.
AC_CHECK_HEADERS([ctype.h err.h errno.h fcntl.h limits.h regex.h stdarg.h])
AC_CHECK_HEADERS([stddef.h stdio.h stdlib.h string.h termios.h unistd.h])
AC_CHECK_HEADERS([libgen.h locale.h wchar.h wctype.h])
AC_CHECK_HEADERS([sys/cdefs.h sys/ioctl.h sys/stat.h sys/types.h sys/uio.h])
AC_CHECK_HEADERS([sys/mman.h sys/param.h])

dnl Check for functions
AC_CHECK_FUNCS(regcomp)
AC_CHECK_FUNCS(regexec)
AC_CHECK_FUNCS(memcpy)
AC_CHECK_FUNCS(wcwidth)

AC_MSG_CHECKING([for working REG_STARTEND])
AC_RUN_IFELSE([AC_LANG_SOURCE([[
#undef NDEBUG
#include <assert.h>
#include <regex.h>
int main(void) {
	regex_t re;
	regmatch_t rm;

	assert(regcomp(&re, "lo", 0) == 0);
	rm.rm_so = 0, rm.rm_eo = 7;
	assert(regexec(&re, "hel\0lo\n", 1, &rm, REG_STARTEND) == 0);
	assert(rm.rm_so == 4 && rm.rm_eo == 6);
	return 0;
}]])],[AC_DEFINE([HAVE_REG_STARTEND], [1], [Do you have a working REG_STARTEND?])
AC_MSG_RESULT([yes])],[AC_MSG_RESULT([no])],[])

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_STRERROR_R

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
