# $NetBSD: buildlink.mk,v 1.4 2001/06/11 01:59:36 jlam Exp $
#
# This Makefile fragment is included by packages that use libjpeg.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define JPEG_REQD to the version of libjpeg desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(JPEG_BUILDLINK_MK)
JPEG_BUILDLINK_MK=	# defined

JPEG_REQD?=		6
DEPENDS+=		jpeg>=${JPEG_REQD}:../../graphics/jpeg

BUILDLINK_PREFIX.jpeg=	${LOCALBASE}
BUILDLINK_FILES.jpeg=	include/jconfig.h
BUILDLINK_FILES.jpeg+=	include/jpeglib.h
BUILDLINK_FILES.jpeg+=	include/jmorecfg.h
BUILDLINK_FILES.jpeg+=	include/jerror.h
BUILDLINK_FILES.jpeg+=	lib/libjpeg.*

BUILDLINK_TARGETS.jpeg=	jpeg-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.jpeg}

pre-configure: ${BUILDLINK_TARGETS.jpeg}
jpeg-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# JPEG_BUILDLINK_MK
