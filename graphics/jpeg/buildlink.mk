# $NetBSD: buildlink.mk,v 1.8 2001/07/27 13:33:29 jlam Exp $
#
# This Makefile fragment is included by packages that use libjpeg.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.jpeg to the dependency pattern
#     for the version of libjpeg desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(JPEG_BUILDLINK_MK)
JPEG_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.jpeg?=	jpeg-6b
DEPENDS+=	${BUILDLINK_DEPENDS.jpeg}:../../graphics/jpeg

EVAL_PREFIX+=		BUILDLINK_PREFIX.jpeg=jpeg
BUILDLINK_PREFIX.jpeg_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.jpeg=	include/jconfig.h
BUILDLINK_FILES.jpeg+=	include/jpeglib.h
BUILDLINK_FILES.jpeg+=	include/jmorecfg.h
BUILDLINK_FILES.jpeg+=	include/jerror.h
BUILDLINK_FILES.jpeg+=	lib/libjpeg.*

BUILDLINK_TARGETS.jpeg=	jpeg-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.jpeg}

pre-configure: ${BUILDLINK_TARGETS.jpeg}
jpeg-buildlink: _BUILDLINK_USE

.endif	# JPEG_BUILDLINK_MK
