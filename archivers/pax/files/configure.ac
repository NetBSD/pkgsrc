dnl Process this file with autoconf to produce a configure script.
AC_PREREQ(2.57)
AC_INIT([pax], [20030905], [grant@NetBSD.org])
AC_CONFIG_SRCDIR([pax.c])
AC_CONFIG_HEADER(config.h)

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S

# Checks for libraries.
AC_CHECK_LIB(util, fparseln)

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([ctype.h grp.h regex.h regexp.h rmt.h stdarg.h])
AC_CHECK_HEADERS([sys/ioctl.h sys/mtio.h sys/resource.h sys/uio.h sys/wait.h])

# Checks for library functions.
AC_CHECK_FUNCS([getrlimit setrlimit])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
