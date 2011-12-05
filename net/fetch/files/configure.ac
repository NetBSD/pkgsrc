dnl $NetBSD: configure.ac,v 1.5 2011/12/05 22:54:22 joerg Exp $

dnl Process this file with autoconf to produce a configure script.
AC_PREREQ(2.52)
AC_INIT([fetch], [1.6], [joerg@NetBSD.org])
AC_CONFIG_HEADER(config.h)

AC_CANONICAL_HOST

AC_CHECK_HEADERS([sys/param.h sys/ioctl.h sys/socket.h sys/stat.h sys/time.h])
AC_CHECK_HEADERS([err.h stdint.h termios.h sysexists.h])

AC_TYPE_INTMAX_T

AC_CHECK_FUNCS([getpass getpassphrase setproctitle])
AC_CHECK_LIB(socket, socket)
AC_CHECK_LIB(nsl, gethostbyname)
AC_CHECK_LIB(crypto, X509_get_issuer_name)
AC_CHECK_LIB(ssl, SSL_read)
AC_CHECK_LIB(fetch, fetchGet)

case "$host_os" in
netbsd)
	AC_DEFINE([PREFER_GETPASS], [], [getpass supports long passwords])
	;;
esac

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
