# $NetBSD: buildlink2.mk,v 1.1.2.3 2002/06/21 23:00:31 jlam Exp $

.if !defined(JPEG_BUILDLINK2_MK)
JPEG_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		jpeg
BUILDLINK_DEPENDS.jpeg?=	jpeg-6b
BUILDLINK_PKGSRCDIR.jpeg?=	../../graphics/jpeg

EVAL_PREFIX+=	BUILDLINK_PREFIX.jpeg=jpeg
BUILDLINK_PREFIX.jpeg_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.jpeg=	include/jconfig.h
BUILDLINK_FILES.jpeg+=	include/jpeglib.h
BUILDLINK_FILES.jpeg+=	include/jmorecfg.h
BUILDLINK_FILES.jpeg+=	include/jerror.h
BUILDLINK_FILES.jpeg+=	lib/libjpeg.*

BUILDLINK_TARGETS+=	jpeg-buildlink

jpeg-buildlink: _BUILDLINK_USE

.endif	# JPEG_BUILDLINK2_MK
