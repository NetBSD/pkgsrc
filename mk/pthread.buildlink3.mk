# $NetBSD: pthread.buildlink3.mk,v 1.5 2004/03/31 20:18:46 seb Exp $
#
# The pthreads strategy for pkgsrc is to "bless" a particular pthread
# package as the Official Pthread Replacement (OPR).  A package that uses
# pthreads may do one of the following:
#
#   (1) Simply include pthread.buildlink3.mk.  This will make the package
#	use the native pthread library if it's available, or else the OPR
#	package.  The value of PTHREAD_TYPE may be checked to be either
#	"native", or the name of the OPR package, or "none", e.g.
#
#	#
#	# package Makefile stuff...
#	#
#	.include "../../mk/pthread.buildlink3.mk"
#
#	.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
#	CONFIGURE_ARGS+=	--without-pthreads
#	.endif
#
#	.include "../../mk/bsd.pkg.mk"
#
#	Note that it's only safe to check and use the value of PTHREAD_TYPE
#	after all other buildlink3.mk files have been included.
#
#   (2) Add "native" to PTHREAD_OPTS prior to including
#	pthread.buildlink3.mk.  This is like case (1), but we only check for
#	the native pthread library, e.g.,
#
#	PTHREAD_OPTS+=	native
#	#
#	# package Makefile stuff...
#	#
#	.include "../../mk/pthread.buildlink3.mk"
#
#	.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
#	CONFIGURE_ARGS+=	--without-pthreads
#	.endif
#
#	.include "../../mk/bsd.pkg.mk"
#
#   (3)	Add "require" to PTHREAD_OPTS prior to including
#	pthread.buildlink3.mk.  This will make the package use the native
#	pthread library or else use the OPR package, and will otherwise set
#	PKG_SKIP_REASON if neither can be used, e.g.,
#
#	PTHREAD_OPTS+=	require
#	#
#	# package Makefile stuff...
#	#
#	.include "../../mk/pthread.buildlink3.mk"
#	.include "../../mk/bsd.pkg.mk"
#
#   (4) Add both "require" and "native" to PTHREAD_OPTS prior to including
#	pthread.buildlink3.mk.  This is like case (3), but we only check for
#	the native pthread library, e.g.,
#
#	PTHREAD_OPTS+=	require native
#	#
#	# more package Makefile stuff...
#	#
#	.include "../../mk/pthread.buildlink3.mk"
#	.include "../../mk/bsd.pkg.mk"
#
# The case where a package must use either the native pthread library or
# some pthread package aside from the OPR is a special case of (2), e.g.,
# if the required pthread package is "ptl2", then:
#
#	PTHREAD_OPTS+=	native
#	#
#	# more package Makefile stuff...
#	#
#	.include "../../mk/pthread.buildlink3.mk"
#
#	.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
#	.  include "../../devel/ptl2/buildlink3.mk"
#	.endif
#
#	.include "../../mk/bsd.pkg.mk"
#
# A package Makefile may add the word "optional" to PTHREAD_OPTS, which
# will override the effects of any instance of the word "require".  This
# should _only_ be used by those packages that can be built with or
# without pthreads _independently_ of whether any of its dependencies need
# pthreads.  Currently, this only only www/mozilla, which uses its own
# threading library if native pthreads is unavailable, despite that it
# uses GTK+, which _does_ need pthreads.
#
###########################################################################
#
# PTHREAD_OPTS represents whether this package requires pthreads, and also
#	whether it needs to be native.  It may include the word "require"
#	to denote that a pthreads implementation is required, and may also
#	include the word "native" to denote that only native pthreads are
#	acceptable.
#
# _PKG_PTHREAD is the fall-back package pthread implementation use by
#	pthread.buildlink3.mk.
#
# _PKG_PTHREAD_COMPAT_PATTERNS matches the ONLY_FOR_PLATFORMS from the
#	Makefile for ${_PKG_PTHREAD}.  It's used to see if ${_PKG_PTHREADS}
#	can actually be used to replace a native pthreads.
#
PTHREAD_BUILDLINK3_MK:=	${PTHREAD_BUILDLINK3_MK}+

_PKG_PTHREAD?=			pth
_PKG_PTHREAD_DEPENDS?=		pth>=2.0.0
_PKG_PTHREAD_PKGSRCDIR?=	../../devel/${_PKG_PTHREAD}
_PKG_PTHREAD_BUILDLINK3_MK?=	${_PKG_PTHREAD_PKGSRCDIR}/buildlink3.mk
_PKG_PTHREAD_COMPAT_PATTERNS=	*-*-*

.include "../../mk/bsd.prefs.mk"

PTHREAD_OPTS?=	# empty
#
# We check for a native pthreads implementation by checking for the presence
# of /usr/include/pthread.h (we might want to make this check stricter).
#
.undef PTHREAD_TYPE
PREFER_NATIVE_PTHREADS?=	YES
.if exists(/usr/include/pthread.h) && ${PREFER_NATIVE_PTHREADS} == "YES"
PTHREAD_TYPE=	native
.else
.  if !empty(PTHREAD_OPTS:Mnative)
PTHREAD_TYPE=	none
.    if !empty(PTHREAD_OPTS:Mrequire) && empty(PTHREAD_OPTS:Moptional)
PKG_SKIP_REASON= "${PKGNAME} requires a native pthreads implementation."
.    endif
.  else
PTHREAD_TYPE=	none
.    for _pattern_ in ${_PKG_PTHREAD_COMPAT_PATTERNS}
.      if !empty(MACHINE_PLATFORM:M${_pattern_})
PTHREAD_TYPE=	${_PKG_PTHREAD}
.      endif
.    endfor
.    if ${PTHREAD_TYPE} == "none" && \
	!empty(PTHREAD_OPTS:Mrequire) && empty(PTHREAD_OPTS:Moptional)
PKG_SKIP_REASON= "${PKGNAME} requires a working pthreads implementation."
.    endif
.  endif
.endif

.if ${PTHREAD_TYPE} == "native"
#
# Link the native pthread libraries and headers into ${BUILDLINK_DIR}.
#
BUILDLINK_PREFIX.pthread=	/usr
BUILDLINK_CFLAGS.pthread=	-pthread
BUILDLINK_LDFLAGS.pthread=	# empty
#
# Handle systems which have pthreads functions in libc_r such as
# FreeBSD 5.x, or fall back to libc if we don't find libc_r.
#
.  if exists(/usr/lib/libpthread.so) || exists(/lib/libpthread.so)
BUILDLINK_LDADD.pthread=	-lpthread
.  elif exists(/usr/lib/libc_r.so)
BUILDLINK_LDADD.pthread=	-lc_r
.  else
BUILDLINK_LDADD.pthread=	# empty
.  endif

.elif ${PTHREAD_TYPE} == "${_PKG_PTHREAD}"
.  if exists(${_PKG_PTHREAD_BUILDLINK3_MK})
.    if !empty(_PKG_PTHREAD_DEPENDS)
BUILDLINK_DEPENDS.${_PKG_PTHREAD}+=	${_PKG_PTHREAD_DEPENDS}
.    endif
BUILDLINK_PREFIX.pthread=	${BUILDLINK_PREFIX.${_PKG_PTHREAD}}
BUILDLINK_CFLAGS.pthread=	${BUILDLINK_CFLAGS.${_PKG_PTHREAD}}
BUILDLINK_LDFLAGS.pthread=	${BUILDLINK_LDFLAGS.${_PKG_PTHREAD}}
BUILDLINK_LDADD.pthread=	-lpthread
.    include "${_PKG_PTHREAD_BUILDLINK3_MK}"
.  else
PKG_SKIP_REASON= "${PKGNAME} needs pthreads, but ${_PKG_PTHREAD_BUILDLINK3_MK} is missing."
.  endif
.endif

.if !empty(PTHREAD_BUILDLINK3_MK:M+)
#
# Define user-visible PTHREAD_CFLAGS and PTHREAD_LDFLAGS as compiler
# options used to compile/link pthreaded code.
#
PTHREAD_CFLAGS=		${BUILDLINK_CFLAGS.pthread}
PTHREAD_LDFLAGS=	${BUILDLINK_LDFLAGS.pthread} ${BUILDLINK_LDADD.pthread}

PTHREADBASE=		${BUILDLINK_PREFIX.pthread}
CONFIGURE_ENV+=		PTHREADBASE=${PTHREADBASE}
MAKE_ENV+=		PTHREADBASE=${PTHREADBASE}
.endif	# PTHREAD_BUILDLINK3_MK
