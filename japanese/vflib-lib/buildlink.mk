# $NetBSD: buildlink.mk,v 1.9 2001/07/27 13:33:31 jlam Exp $
#
# This Makefile fragment is included by packages that use VFlib.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.vflib to the dependency pattern
#     for the version of VFlib desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(VFLIB_BUILDLINK_MK)
VFLIB_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.vflib?=	ja-vflib-lib>=2.24.2
DEPENDS+=	${BUILDLINK_DEPENDS.vflib}:../../japanese/vflib-lib

EVAL_PREFIX+=			BUILDLINK_PREFIX.vflib=ja-vflib-lib
BUILDLINK_PREFIX.vflib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.vflib=		include/VF.h
BUILDLINK_FILES.vflib+=		lib/libVFlib2.*

.include "../../graphics/freetype-lib/buildlink.mk"

BUILDLINK_TARGETS.vflib=	vflib-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.vflib}

pre-configure: ${BUILDLINK_TARGETS.vflib}
vflib-buildlink: _BUILDLINK_USE

.endif	# VFLIB_BUILDLINK_MK
