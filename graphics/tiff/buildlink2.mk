# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 18:39:23 jlam Exp $

.if !defined(TIFF_BUILDLINK2_MK)
TIFF_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		tiff
BUILDLINK_DEPENDS.tiff?=	tiff>=3.5.4
BUILDLINK_PKGSRCDIR.tiff?=	../../graphics/tiff

EVAL_PREFIX+=	BUILDLINK_PREFIX.tiff=tiff
BUILDLINK_PREFIX.tiff_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.tiff=	include/tiff.h
BUILDLINK_FILES.tiff+=	include/tiffconf.h
BUILDLINK_FILES.tiff+=	include/tiffio.h
BUILDLINK_FILES.tiff+=	include/tiffvers.h
BUILDLINK_FILES.tiff+=	lib/libtiff.*

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"

BUILDLINK_TARGETS+=	tiff-buildlink

tiff-buildlink: _BUILDLINK_USE

.endif	# TIFF_BUILDLINK2_MK
