# $NetBSD: buildlink2.mk,v 1.1.2.3 2002/06/21 23:00:33 jlam Exp $

.if !defined(PNG_BUILDLINK2_MK)
PNG_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		png
BUILDLINK_DEPENDS.png?=		png>=1.2.1
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
