# $NetBSD: pthread.buildlink.mk,v 1.1 2001/12/24 19:29:32 jlam Exp $
#
# This Makefile fragment is included by packages that use pthreads.
# This Makefile fragment is also included directly by bsd.prefs.mk.
#
# To use this Makefile fragment, simply:
#
# (1) Define USE_PTHREAD _before_ including bsd.prefs.mk in the package
#     Makefile,
# (2) Optionally set PTHREAD_TYPE to force the use of a specific pthread
#     implementation,
# (3) Include bsd.prefs.mk in the package Makefile,
# (4) And include this Makefile fragment in the package Makefile.
#
# The value of ${PTHREAD_TYPE} may be used after the inclusion of
# bsd.prefs.mk, which indirectly sets this value by including this file.
# E.g.,
#
# USE_PTHREAD=	native
# .include "../../mk/bsd.prefs.mk"
#
# .if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
# CONFIGURE_ARGS+=	--without-pthreads
# .endif
#
###########################################################################
#
# USE_PTHREAD is a list of pthread implementations that may be used, and is
#	set in a package Makefile.  Its values are either "native" or any
#	of the package pthread implementations listed in ${_PKG_PTHREADS},
#	e.g. "USE_PTHREAD = native pth".
#
# _PKG_PTHREADS is the list of package pthread implementations recognized by
#	pthread.buildlink.mk
#
.if defined(USE_PTHREAD)
_PKG_PTHREADS?=		pth ptl2 mit-pthreads unproven-pthreads

.for __valid_pthread__ in ${USE_PTHREAD}
.  if !empty(_PKG_PTHREADS:M${__valid_pthread__})
_PKG_PTHREAD_TYPE?=	${__valid_pthread__}
.  endif
.endfor
_PKG_PTHREAD_TYPE?=	none

# We check for a native pthread implementation by checking for the presence
# of /usr/include/pthread.h (we might want to make this check stricter).
#
.if !empty(USE_PTHREAD:Mnative)
.  if exists(/usr/include/pthread.h)
PTHREAD_TYPE?=		native
.  else
PTHREAD_TYPE?=		${_PKG_PTHREAD_TYPE}
.  endif
.endif
.endif	# USE_PTHREAD
#
###########################################################################
#
# Only allow the following section to be seen _after_ the first time this
# file is included.  This allows this file to be included by bsd.prefs.mk
# and also to be included in a package Makefile as is done normally, and
# allows us to consolidate the pthread Makefile logic in one place.  We
# want this, as we'd like for PTHREAD_TYPE to be available to package
# Makefiles after they pull in bsd.prefs.mk.
#
_PTHREAD_BUILDLINK_MK_NPASSES?=	# empty
_PTHREAD_BUILDLINK_MK_NPASSES:=	${_PTHREAD_BUILDLINK_MK_NPASSES}.

.if !empty(_PTHREAD_BUILDLINK_MK_NPASSES:M..)
.if !defined(PTHREAD_BUILDLINK_MK)
PTHREAD_BUILDLINK_MK=	# defined

.if ${PTHREAD_TYPE} == "native"
#
# Link the native pthread libraries and headers into ${BUILDLINK_DIR}.
#
.  include "../../mk/bsd.buildlink.mk"
BUILDLINK_PREFIX.pthread=	/usr
BUILDLINK_FILES.pthread=	include/pthread.h
BUILDLINK_FILES.pthread+=	lib/libpthread.*

BUILDLINK_TARGETS.pthread=	pthread-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.pthread}

pre-configure: ${BUILDLINK_TARGETS.pthread}
pthread-buildlink: _BUILDLINK_USE

.elif ${PTHREAD_TYPE} == "pth"
.  include "../../devel/pth/buildlink.mk"
#
# XXX The remaining pthread packages here need to have sensible buildlink.mk
# XXX created that may all be used more-or-less interchangeably.  This is
# XXX slightly challenging, so please beware in the implementation.
#
.elif ${PTHREAD_TYPE} == "ptl2"
DEPENDS+=		ptl>=2.1.7:../../devel/ptl2
.elif ${PTHREAD_TYPE} == "mit-pthreads"
DEPENDS+=		mit-pthreads-1.60b6:../../devel/mit-pthreads
.elif ${PTHREAD_TYPE} == "unproven-pthreads"
DEPENDS+=		unproven-threads>=0.17:../../devel/unproven-pthreads
.endif

.endif	# PTHREAD_BUILDLINK_MK
.endif	# _PTHREAD_BUILDLINK_MK_NPASSES
