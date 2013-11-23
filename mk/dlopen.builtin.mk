# $NetBSD: dlopen.builtin.mk,v 1.27 2013/11/23 09:10:14 obache Exp $

BUILTIN_PKG:=	dl

BUILTIN_FIND_LIBS:=		dl
BUILTIN_FIND_HEADERS_VAR:=	H_DL
BUILTIN_FIND_HEADERS.H_DL=	dlfcn.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.dl)
IS_BUILTIN.dl=	no
.  if empty(H_DL:M${LOCALBASE}/*) && exists(${H_DL})
IS_BUILTIN.dl=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.dl

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
#
# We ignore the value of PREFER_PKGSRC and PREFER_NATIVE because for every
# platform (unless overridden in the platform file), we can only use the
# built-in dynamic linker functions.
#
.if !defined(USE_BUILTIN.dl)
USE_BUILTIN.dl=	${IS_BUILTIN.dl}
.endif
MAKEVARS+=	USE_BUILTIN.dl

# The following platforms require pthreads to be linked into the
# application if it uses dlopen() or else the applications will core
# dump when they dlopen a shared module that _is_ linked with pthread
# support.
# It is not required for NetBSD>=5 if just linked with pthread or using
# pthread_mutex_*(), but need if using pthread_create() / pthread_join().
#
_BLNK_DLOPEN_REQUIRE_PTHREAD_PLATFORMS=					\
	NetBSD-2.[0-9]_*-*						\
	NetBSD-2.[0-9]-* NetBSD-2.[0-9].[0-9]*-*			\
	NetBSD-2.[0-8][0-9]*-* NetBSD-2.9[0-8]*-*			\
	NetBSD-2.99.[0-9]-* NetBSD-2.99.10-*				\
	NetBSD-[3-9]*-*							\
	NetBSD-[1-9][0-9]*-*						\
	OpenBSD-*-*

.if !defined(_BLNK_DLOPEN_REQUIRE_PTHREADS)
_BLNK_DLOPEN_REQUIRE_PTHREADS?=	no
.  for _pattern_ in ${_BLNK_DLOPEN_REQUIRE_PTHREAD_PLATFORMS}
.    if !empty(MACHINE_PLATFORM:M${_pattern_})
.      if !empty(PREFER_NATIVE_PTHREADS:M[yY][eE][sS])
_BLNK_DLOPEN_REQUIRE_PTHREADS=	yes
.      endif
.    endif
.  endfor
.endif
MAKEVARS+=	_BLNK_DLOPEN_REQUIRE_PTHREADS
#
# DLOPEN_REQUIRE_PTHREADS is a user- and package-settable yes/no variable
#	whose value decides whether pthread.buildlink3.mk is automatically
#	included or not.  Its default value depends on whether native
#	pthreads exist.
#
.if defined(DLOPEN_REQUIRE_PTHREADS)
_BLNK_DLOPEN_REQUIRE_PTHREADS:=	${DLOPEN_REQUIRE_PTHREADS}
.else
DLOPEN_REQUIRE_PTHREADS=        ${_BLNK_DLOPEN_REQUIRE_PTHREADS}
.endif

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.dl?=	no
.if !empty(CHECK_BUILTIN.dl:M[nN][oO])

.  if !empty(USE_BUILTIN.dl:M[yY][eE][sS])
.    if empty(H_DL:M__nonexistent__)
.      if !empty(H_DL:M/usr/*)
BUILDLINK_PREFIX.dl=	/usr
.      else
BUILDLINK_PREFIX.dl=	# empty
.      endif
.    endif
.    if !empty(BUILTIN_LIB_FOUND.dl:M[yY][eE][sS])
#
# No need to add this to BUILDLINK_LIBS.dl since most GNU configure
# scripts already check for -ldl themselves.
#
BUILDLINK_LDADD.dl=	-ldl
.    endif
.    if !empty(_BLNK_DLOPEN_REQUIRE_PTHREADS:M[yY][eE][sS])
.      include "../../mk/pthread.buildlink3.mk"
.      include "../../mk/pthread.builtin.mk"
BUILDLINK_CFLAGS.dl+=	${PTHREAD_CFLAGS}
BUILDLINK_LDFLAGS.dl+=	${PTHREAD_LDFLAGS}
BUILDLINK_LIBS.dl+=	${PTHREAD_LIBS}
.    endif
.  endif

.endif	# CHECK_BUILTIN.dl
