# $NetBSD: buildlink.mk,v 1.4 2001/06/11 01:59:37 jlam Exp $
#
# This Makefile fragment is included by packages that use VFlib.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define VFLIB_REQD to the version of VFlib desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(VFLIB_BUILDLINK_MK)
VFLIB_BUILDLINK_MK=	# defined

VFLIB_REQD?=		2.24.2
DEPENDS+=		ja-vflib-lib>=${VFLIB_REQD}:../../japanese/vflib-lib

BUILDLINK_PREFIX.vflib=		${LOCALBASE}
BUILDLINK_FILES.vflib=		include/VF.h
BUILDLINK_FILES.vflib+=		lib/libVFlib2.*

.include "../../graphics/freetype-lib/buildlink.mk"

BUILDLINK_TARGETS.vflib=	vflib-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.vflib}

pre-configure: ${BUILDLINK_TARGETS.vflib}
vflib-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# VFLIB_BUILDLINK_MK
