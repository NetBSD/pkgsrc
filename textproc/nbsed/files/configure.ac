dnl $Id: configure.ac,v 1.8 2004/08/27 03:45:08 jlam Exp $
dnl Process this file with autoconf to produce a configure script.
AC_PREREQ(2.57)
AC_INIT([sed],[20040821],[agc@NetBSD.org])
AC_CONFIG_SRCDIR([main.c])
AC_CONFIG_HEADER(config.h)
AC_ARG_PROGRAM

AC_CANONICAL_HOST
CANONICAL_HOST=$host
AC_SUBST(CANONICAL_HOST)

# Checks for programs.
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
AC_HEADER_STDC
AC_CHECK_HEADERS([ctype.h err.h errno.h fcntl.h limits.h regex.h stdarg.h])
AC_CHECK_HEADERS([stddef.h stdio.h stdlib.h string.h termios.h unistd.h])
AC_CHECK_HEADERS([sys/cdefs.h sys/ioctl.h sys/stat.h sys/types.h sys/uio.h])

dnl Check for functions
AC_CHECK_FUNCS(fgetln)
AC_CHECK_FUNCS(regcomp)
AC_CHECK_FUNCS(regexec)
AC_CHECK_FUNCS(memcpy)
AC_CHECK_FUNCS(getprogname)
AC_CHECK_FUNCS(setprogname)

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_STRERROR_R

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
