# $NetBSD: buildlink.mk,v 1.9 2001/07/27 13:33:31 jlam Exp $
#
# This Makefile fragment is included by packages that use libtiff.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.tiff to the dependency pattern
#     for the version of libtiff desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(TIFF_BUILDLINK_MK)
TIFF_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.tiff?=	tiff>=3.5.4
DEPENDS+=	${BUILDLINK_DEPENDS.tiff}:../../graphics/tiff

EVAL_PREFIX+=		BUILDLINK_PREFIX.tiff=tiff
BUILDLINK_PREFIX.tiff_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.tiff=	include/tiff.h
BUILDLINK_FILES.tiff+=	include/tiffconf.h
BUILDLINK_FILES.tiff+=	include/tiffio.h
BUILDLINK_FILES.tiff+=	lib/libtiff.*

.include "../../devel/zlib/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"

BUILDLINK_TARGETS.tiff=	tiff-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.tiff}

pre-configure: ${BUILDLINK_TARGETS.tiff}
tiff-buildlink: _BUILDLINK_USE

.endif	# TIFF_BUILDLINK_MK
