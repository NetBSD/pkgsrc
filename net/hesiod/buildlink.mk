# $NetBSD: buildlink.mk,v 1.2 2001/11/29 13:32:27 jlam Exp $
#
# This Makefile fragment is included by packages that use the Hesiod name 
# service library. 
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define USE_HESIOD to force use of the hesiod library
#     included in this package.
# (2) Optionally define BUILDLINK_DEPENDS.hesiod to the dependency pattern
#     for the version of hesiod library desired.
# (3) Include this Makefile fragment in the package Makefile,
# (4) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (5) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(HESIOD_BUILDLINK_MK)
HESIOD_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.hesiod?=	hesiod>=3.0.2

.if defined(USE_HESIOD)
_NEED_HESIOD=		YES
.else
.  if exists(/usr/include/hesiod.h)
_NEED_HESIOD=		NO
.  else
_NEED_HESIOD=		YES
.  endif
.endif

.if ${_NEED_HESIOD} == "YES"
BUILD_DEPENDS+=		${BUILDLINK_DEPENDS.hesiod}:../../net/hesiod
EVAL_PREFIX+=		BUILDLINK_PREFIX.hesiod=hesiod
BUILDLINK_PREFIX.hesiod_DEFAULT=	${LOCALBASE}
.else
BUILDLINK_PREFIX.hesiod=	/usr
.endif

BUILDLINK_FILES.hesiod=		include/hesiod.h
# if lib/libhesiod.* does not exists assume hesiod service is included in libc
BUILDLINK_FILES.hesiod+=	lib/libhesiod.*

BUILDLINK_TARGETS.hesiod=	hesiod-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.hesiod}

pre-configure: ${BUILDLINK_TARGETS.hesiod}
hesiod-buildlink: _BUILDLINK_USE

.endif	# HESIOD_BUILDLINK_MK
