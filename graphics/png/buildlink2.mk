# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 18:39:21 jlam Exp $

.if !defined(PNG_BUILDLINK2_MK)
PNG_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		png
BUILDLINK_DEPENDS.png?=		png>=1.2.4
BUILDLINK_PKGSRCDIR.png?=	../../graphics/png

EVAL_PREFIX+=	BUILDLINK_PREFIX.png=png
BUILDLINK_PREFIX.png_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.png=	include/png.h
BUILDLINK_FILES.png+=	include/pngconf.h
BUILDLINK_FILES.png+=	lib/libpng.*

.include "../../devel/zlib/buildlink2.mk"

BUILDLINK_TARGETS+=	png-buildlink

png-buildlink: _BUILDLINK_USE

.endif	# PNG_BUILDLINK2_MK
