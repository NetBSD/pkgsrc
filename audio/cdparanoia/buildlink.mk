# $NetBSD: buildlink.mk,v 1.1 2002/04/27 10:37:07 rh Exp $
#
# This Makefile fragment is included by packages that use the library
# provided by cdparanoia.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.cdparanoia to the dependency
#     pattern for the version of cdparanoia desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(CDPARANOIA_BUILDLINK_MK)
CDPARANOIA_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.cdparanoia?=	cdparanoia>=3.0
DEPENDS+=	${BUILDLINK_DEPENDS.cdparanoia}:../../audio/cdparanoia

EVAL_PREFIX+=	BUILDLINK_PREFIX.cdparanoia=cdparanoia
BUILDLINK_PREFIX.cdparanoia_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.cdparanoia=	include/cdparanoia/*
BUILDLINK_FILES.cdparanoia+=	lib/libcdda_paranoia.*
BUILDLINK_FILES.cdparanoia+=	lib/libcdda_interface.*

BUILDLINK_TARGETS.cdparanoia=	cdparanoia-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.cdparanoia}

pre-configure: ${BUILDLINK_TARGETS.cdparanoia}
cdparanoia-buildlink: _BUILDLINK_USE

.endif	# CDPARANOIA_BUILDLINK_MK
