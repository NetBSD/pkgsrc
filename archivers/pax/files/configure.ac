dnl Process this file with autoconf to produce a configure script.
AC_PREREQ(2.57)
AC_INIT([pax], [20040802], [grant@NetBSD.org])
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
AC_CHECK_HEADERS([ctype.h err.h errno.h fnctl.h fts.h getopt.h grp.h \
	limits.h netdb.h paths.h pwd.h regex.h regexp.h rmt.h \
	signal.h stdarg.h stddef.h stdio.h stdlib.h string.h strings.h \
	time.h tzfile.h unistd.h util.h vis.h])
AC_CHECK_HEADERS([sys/cdefs.h sys/ioctl.h sys/mman.h sys/mtio.h sys/param.h \
	sys/resource.h sys/stat.h sys/tape.h sys/time.h sys/types.h sys/uio.h \
	sys/wait.h])
AC_CHECK_MEMBERS([struct stat.st_flags],,, [#include <sys/stat.h>])
AC_CHECK_DECLS([UF_SETTABLE, SF_SETTABLE])
AH_BOTTOM([/* Define to 1 if the user- and root-changeable masks were detected */
#if HAVE_STRUCT_STAT_ST_FLAGS && HAVE_DECL_UF_SETTABLE && HAVE_DECL_SF_SETTABLE
#define HAVE_FILE_FLAGS 1
#endif
])

# Checks for library functions.
AC_CHECK_FUNCS([fchroot lutimes])
AC_CHECK_FUNCS([getrlimit setrlimit])

AC_ARG_PROGRAM
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
