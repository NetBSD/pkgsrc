dnl Process this file with autoconf to produce a configure script.
AC_PREREQ(2.52)
AC_INIT([pkg_install], [20030823], [grant@NetBSD.org])
AC_CONFIG_SRCDIR([lib/plist.c])
AC_CONFIG_HEADER(lib/config.h)

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

AC_PATH_PROG(CHMOD, chmod)
AC_PATH_PROG(CMP, cmp)
AC_PATH_PROG(CP, cp)
AC_PATH_PROG(ENV, env)
AC_PATH_PROG(FIND, find)
AC_PATH_PROG(GREP, grep)
AC_PATH_PROG(LN, ln)
AC_PATH_PROG(MKDIR, mkdir)
AC_PATH_PROG(RMDIR, rmdir)
AC_PATH_PROG(RM, rm)
AC_PATH_PROG(SED, sed)
AC_PATH_PROG(SORT, sort)
AC_PATH_PROG(TOUCH, touch)

AUTOCONF=${AUTOCONF-"$srcdir/missing --run autoconf"}
AC_SUBST(AUTOCONF)
AUTOHEADER=${AUTOHEADER-"$srcdir/missing --run autoheader"}
AC_SUBST(AUTOHEADER)

dnl Set the default pkg dbdir
AC_ARG_WITH(pkgdbdir,
[  --with-pkgdbdir=DIR     Where to put the pkg database (/var/db/pkg)],
[ pkgdbdir="$with_pkgdbdir" ],
[ pkgdbdir="/var/db/pkg" ])
AC_SUBST(pkgdbdir)

AC_ARG_WITH(ftp,
[  --with-ftp=path         Path to tnftp (PREFIX/bin/ftp)],
[ ftp="$with_ftp" ],
[ ftp='$(prefix)/bin/ftp' ])
AC_SUBST(ftp)

AC_ARG_WITH(tar,
[  --with-tar=path         Path to pax-as-tar (PREFIX/bin/tar)],
[ tar="$with_tar" ],
[ tar='$(prefix)/bin/tar' ])
AC_SUBST(tar)

AC_ARG_WITH(pax,
[  --with-pax=path         Path to pax (PREFIX/bin/pax)],
[ pax="$with_pax" ],
[ pax='$(prefix)/bin/pax' ])
AC_SUBST(pax)

AC_ARG_WITH(mtree,
[  --with-mtree=path       Path to mtree (PREFIX/sbin/mtree)],
[ mtree="$with_mtree" ],
[ mtree='$(sbindir)/mtree' ])
AC_SUBST(mtree)

dnl Checks for libraries.
AC_CHECK_LIB(db1, dbopen)
AC_SEARCH_LIBS(tgetent, [termcap termlib curses ncurses])

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([db1/db.h db.h])
AC_CHECK_HEADERS([fnmatch.h md5.h regex.h])
AC_CHECK_HEADERS([sys/ioctl.h sys/resource.h sys/wait.h])

# Checks for library functions.
AC_CHECK_FUNCS([chflags dbopen tgetent vfork])
AC_CHECK_FUNCS([getrlimit setrlimit])

AH_BOTTOM(
#if !HAVE_VFORK
# define vfork fork
#endif
)

AC_CONFIG_FILES([Makefile add/Makefile admin/Makefile create/Makefile \
	delete/Makefile info/Makefile lib/Makefile view/Makefile \
	view/linkfarm.sh view/pkg_view.sh])
AC_OUTPUT
