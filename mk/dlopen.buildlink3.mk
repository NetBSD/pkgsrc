# $NetBSD: dlopen.buildlink3.mk,v 1.2 2004/11/25 21:43:19 jlam Exp $
#
# This Makefile fragment is included by package Makefiles and
# buildlink3.mk files for the packages that use dlopen().
#
# DLOPEN_REQUIRE_PTHREADS is a user- and package-settable yes/no variable
#	whose value decides whether pthread.buildlink3.mk is automatically
#	included or not.  Its default value depends on whether native
#	pthreads exist.
#
# Including pthread.buildlink3.mk is deferred until bsd.pkg.mk.

.include "../../mk/bsd.prefs.mk"

# The following platforms require pthreads to be linked into the
# application if it uses dlopen() or else the applications will core
# dump when they dlopen a shared module that _is_ linked with pthread
# support.
#
_DLOPEN_REQUIRE_PTHREAD_PLATFORMS=					\
	NetBSD-2.[0-9] NetBSD-2.[0-8][0-9]* NetBSD-2.9[0-8]*		\
	NetBSD-2.99.[0-9] NetBSD-2.99.10

_DLOPEN_REQUIRE_PTHREADS?=	no
.for _pattern_ in ${_DLOPEN_REQUIRE_PTHREAD_PLATFORMS}
.  if !empty(MACHINE_PLATFORM:${_pattern_})
.    if !empty(PREFER_NATIVE_PTHREADS:M[yY][eE][sS])
_DLOPEN_REQUIRE_PTHREADS=	yes
.    endif
.  endif
.endfor

.if defined(DLOPEN_REQUIRE_PTHREADS)
_DLOPEN_REQUIRE_PTHREADS=	${DLOPEN_REQUIRE_PTHREADS}
.else
DLOPEN_REQUIRE_PTHREADS=	${_DLOPEN_REQUIRE_PTHREADS}
.endif
