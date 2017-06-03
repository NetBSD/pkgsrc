dnl Copyright (c) 2017 The NetBSD Foundation, Inc.
dnl All rights reserved.
dnl
dnl This code is derived from software contributed to The NetBSD Foundation
dnl by Johnny C. Lam.
dnl
dnl Redistribution and use in source and binary forms, with or without
dnl modification, are permitted provided that the following conditions
dnl are met:
dnl 1. Redistributions of source code must retain the above copyright
dnl    notice, this list of conditions and the following disclaimer.
dnl 2. Redistributions in binary form must reproduce the above copyright
dnl    notice, this list of conditions and the following disclaimer in the
dnl    documentation and/or other materials provided with the distribution.
dnl
dnl THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
dnl ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
dnl TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
dnl PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
dnl BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
dnl CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
dnl SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
dnl INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
dnl CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
dnl ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
dnl POSSIBILITY OF SUCH DAMAGE.
dnl

AC_INIT([pkgtasks-1], [1.10], [jlam@NetBSD.org])


AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_SRCDIR([load.subr])
AC_CONFIG_FILES([Makefile])


AM_INIT_AUTOMAKE([foreign subdir-objects -Wall])


AC_ARG_VAR([POSIX_SHELL], [Location of the POSIX shell interpreter to use])
if test "${POSIX_SHELL}" = ""; then
	AC_PATH_PROGS(POSIX_SHELL, [ksh bash sh])
else
	case ${POSIX_SHELL} in
	/*)	: "path is an absolute path"
		;;
	*)	AC_MSG_ERROR([POSIX_SHELL must hold an absolute path])
		;;
	esac
fi
if test "${POSIX_SHELL}" = ""; then
	AC_MSG_ERROR([No POSIX shell interpreter found; maybe set POSIX_SHELL?])
fi


AC_PATH_PROG([KYUA], [kyua])
AM_CONDITIONAL([HAVE_KYUA], [test -n "${KYUA}"])

AC_PROG_MKDIR_P
AC_PROG_SED

AC_SUBST(testsdir, '${exec_prefix}/tests')
AC_SUBST(pkgtestsdir, '${testsdir}/$(PACKAGE)')


AC_OUTPUT
