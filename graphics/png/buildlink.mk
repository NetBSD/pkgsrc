# $NetBSD: buildlink.mk,v 1.11 2002/07/19 14:33:08 fredb Exp $
#
# This Makefile fragment is included by packages that use libpng.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.png to the dependency pattern
#     for the version of libpng desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(PNG_BUILDLINK_MK)
PNG_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.png?=	png>=1.2.4
DEPENDS+=		${BUILDLINK_DEPENDS.png}:../../graphics/png

EVAL_PREFIX+=		BUILDLINK_PREFIX.png=png
BUILDLINK_PREFIX.png_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.png=	include/png.h
BUILDLINK_FILES.png+=	include/pngconf.h
BUILDLINK_FILES.png+=	lib/libpng.*

.include "../../devel/zlib/buildlink.mk"

BUILDLINK_TARGETS.png=	png-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.png}

pre-configure: ${BUILDLINK_TARGETS.png}
png-buildlink: _BUILDLINK_USE

.endif	# PNG_BUILDLINK_MK
