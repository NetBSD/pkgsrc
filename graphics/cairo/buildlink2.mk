# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/02/03 12:16:43 recht Exp $
#

.if !defined(CAIRO_BUILDLINK2_MK)
CAIRO_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			cairo
BUILDLINK_DEPENDS.cairo?=		cairo>=0.1.17
BUILDLINK_PKGSRCDIR.cairo?=		../../graphics/cairo

EVAL_PREFIX+=	BUILDLINK_PREFIX.cairo=cairo
BUILDLINK_PREFIX.cairo_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.cairo+=	include/cairo-features.h
BUILDLINK_FILES.cairo+=	include/cairo.h
BUILDLINK_FILES.cairo+=	lib/libcairo.*

BUILDLINK_DEPENDS.freetype2=  freetype2>=2.1.5

.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/libpixman/buildlink2.mk"
.include "../../fonts/Xft2/buildlink2.mk"

BUILDLINK_TARGETS+=	cairo-buildlink

cairo-buildlink: _BUILDLINK_USE

.endif	# CAIRO_BUILDLINK2_MK
