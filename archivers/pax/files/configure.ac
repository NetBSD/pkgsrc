dnl Process this file with autoconf to produce a configure script.
AC_PREREQ(2.57)
AC_INIT([pax], [20030915], [grant@NetBSD.org])
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
AC_CHECK_HEADERS([ctype.h errno.h err.h fnctl.h fts.h getopt.h grp.h \
	inttypes.h limits.h netdb.h paths.h pwd.h regexp.h regex.h rmt.h \
	signal.h stdarg.h stddef.h stdio.h stdlib.h strings.h string.h \
	time.h tzfile.h unistd.h vis.h])
AC_CHECK_HEADERS([sys/cdefs.h sys/ioctl.h sys/mtio.h sys/param.h \
	sys/resource.h sys/stat.h sys/tape.h sys/time.h sys/types.h sys/uio.h \
	sys/wait.h])

# Checks for library functions.
AC_CHECK_FUNCS([getrlimit setrlimit])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
