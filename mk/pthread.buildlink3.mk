# $NetBSD: pthread.buildlink3.mk,v 1.33 2019/06/30 21:28:28 rillig Exp $
#
# The pthreads strategy for pkgsrc is to "bless" a particular pthread
# package as the Official Pthread Replacement (OPR).  The following
# variables may be set before including this file:
#
# PTHREAD_OPTS?= # empty
#	A list of options to configure the search for a suitable pthreads
#	implementation.
#
#	"native" means that only a native pthreads implementation is
#		acceptable.
#
#	"optional" will override the effects of any instance of
#		"require".  This should _only_ be used by those packages
#		that can be built with or without pthreads independently
#		of whether any of its dependencies need pthreads.
#		Currently, this is only www/mozilla, which uses its own
#		threading library if native pthreads are unavailable,
#		despite that it uses GTK+, which _does_ need pthreads.
#
#	"require" means that the package is skipped silently when no
#		implementation can be found.
#
#	By default, the native pthreads implementation is used if it's
#	available. Otherwise the OPR is used.
#
# PTHREAD_AUTO_VARS?= no
#	This variable specifies whether the values of the variables
#	PTHREAD_{CFLAGS,CPPFLAGS,LDFLAGS,LIBS} should be automatically
#	added to their respective variables.
#
# After inclusion of this file, the following variables may be examined:
#
# PTHREAD_TYPE
#	The type of pthreads implementation that has been found.
#
#	"native" means that the native pthreads implementation is used.
#
#	"none" means that no suitable pthreads implementation could be
#		found.
#
#	Any other value is the name of the package that is used as the
#	pthread implementation.
#
#	Note that it's only safe to check and use the value of PTHREAD_TYPE
#	after all other buildlink3.mk files have been included.
#
# The case where a package must use either the native pthread library or
# some pthread package aside from the OPR (e.g. "ptl2") can be solved as
# follows:
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

PTHREAD_BUILDLINK3_MK:=	${PTHREAD_BUILDLINK3_MK}+

_VARGROUPS+=		pthread
_PKG_VARS.pthread=	PTHREAD_OPTS PTHREAD_AUTO_VARS
_SYS_VARS.pthread=	PTHREAD_TYPE PTHREAD_CFLAGS PTHREAD_LDFLAGS PTHREAD_LIBS

# The fall-back package pthread implementation
_PKG_PTHREAD?=			pth
_PKG_PTHREAD_DEPENDS?=		pth>=2.0.0
_PKG_PTHREAD_PKGSRCDIR?=	../../devel/${_PKG_PTHREAD}
_PKG_PTHREAD_BUILDLINK3_MK?=	${_PKG_PTHREAD_PKGSRCDIR}/buildlink3.mk

# _PKG_PTHREAD_COMPAT_PATTERNS matches the ONLY_FOR_PLATFORMS from the
# Makefile for ${_PKG_PTHREAD}.  It is used to see if ${_PKG_PTHREADS}
# can actually be used to replace a native pthreads.
_PKG_PTHREAD_COMPAT_PATTERNS=	*-*-*

.include "bsd.fast.prefs.mk"

PTHREAD_OPTS?=	# empty

CHECK_BUILTIN.pthread:=  yes
.include "pthread.builtin.mk"
CHECK_BUILTIN.pthread:=  no

#
# Set the value of PTHREAD_TYPE depending on the platform and what's
# available in the base system.
#
.undef PTHREAD_TYPE
.if defined(USE_BUILTIN.pthread) && \
    !empty(USE_BUILTIN.pthread:M[yY][eE][sS]) && \
    !empty(PREFER_NATIVE_PTHREADS:M[yY][eE][sS])
PTHREAD_TYPE=	native
.else
.  if !empty(PTHREAD_OPTS:Mnative)
PTHREAD_TYPE=	none
.    if !empty(PTHREAD_OPTS:Mrequire) && empty(PTHREAD_OPTS:Moptional)
PKG_SKIP_REASON+= "${PKGNAME} requires a native pthreads implementation."
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
PKG_SKIP_REASON+= "${PKGNAME} requires a working pthreads implementation."
.    endif
.  endif
.endif

PTHREAD_AUTO_VARS?=	no

.if ${PTHREAD_TYPE} == "native"
BUILDLINK_TREE+=		pthread -pthread
BUILDLINK_BUILTIN_MK.pthread=	../../mk/pthread.builtin.mk
BUILDLINK_AUTO_VARS.pthread?=	${PTHREAD_AUTO_VARS}
.elif ${PTHREAD_TYPE} == "${_PKG_PTHREAD}"
.  if exists(${_PKG_PTHREAD_BUILDLINK3_MK})
.    if !empty(_PKG_PTHREAD_DEPENDS)
BUILDLINK_API_DEPENDS.${_PKG_PTHREAD}+=	${_PKG_PTHREAD_DEPENDS}
.    endif
.    include "${_PKG_PTHREAD_BUILDLINK3_MK}"
BUILDLINK_PREFIX.pthread=		${BUILDLINK_PREFIX.${_PKG_PTHREAD}}
BUILDLINK_CFLAGS.pthread=		${BUILDLINK_CFLAGS.${_PKG_PTHREAD}}
BUILDLINK_CPPFLAGS.${_PKG_PTHREAD}?=	-D_REENTRANT
BUILDLINK_CPPFLAGS.pthread=		${BUILDLINK_CPPFLAGS.${_PKG_PTHREAD}}
BUILDLINK_LDFLAGS.pthread=		${BUILDLINK_LDFLAGS.${_PKG_PTHREAD}}
BUILDLINK_LIBS.${_PKG_PTHREAD}?=	-lpthread
BUILDLINK_LIBS.pthread=			${BUILDLINK_LIBS.${_PKG_PTHREAD}}
BUILDLINK_AUTO_VARS.${_PKG_PTHREAD}?=	${PTHREAD_AUTO_VARS}
BUILDLINK_AUTO_VARS.pthread=		${BUILDLINK_AUTO_VARS.${_PKG_PTHREAD}}
.  else
PKG_FAIL_REASON+= ${PKGNAME:Q}" needs pthreads, but "${_PKG_PTHREAD_BUILDLINK3_MK:Q}" is missing."
.  endif
.endif

.if !empty(PTHREAD_BUILDLINK3_MK:M+)
#
# Define user-visible PTHREAD_{CFLAGS,LDFLAGS,LIBS} as compiler options
# used to compile/link pthreaded code.
#
PTHREAD_CFLAGS=		${BUILDLINK_CFLAGS.pthread}
PTHREAD_CFLAGS+=	${BUILDLINK_CPPFLAGS.pthread}
PTHREAD_LDFLAGS=	${BUILDLINK_LDFLAGS.pthread}
PTHREAD_LIBS=		${BUILDLINK_LIBS.pthread}
CONFIGURE_ENV+=		PTHREAD_CFLAGS=${PTHREAD_CFLAGS:Q}
CONFIGURE_ENV+=		PTHREAD_LDFLAGS=${PTHREAD_LDFLAGS:Q}
CONFIGURE_ENV+=		PTHREAD_LIBS=${PTHREAD_LIBS:Q}
MAKE_ENV+=		PTHREAD_CFLAGS=${PTHREAD_CFLAGS:Q}
MAKE_ENV+=		PTHREAD_LDFLAGS=${PTHREAD_LDFLAGS:Q}
MAKE_ENV+=		PTHREAD_LIBS=${PTHREAD_LIBS:Q}

PTHREADBASE=		${BUILDLINK_PREFIX.pthread}
CONFIGURE_ENV+=		PTHREADBASE=${PTHREADBASE:Q}
MAKE_ENV+=		PTHREADBASE=${PTHREADBASE:Q}

.endif	# PTHREAD_BUILDLINK3_MK
