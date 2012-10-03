# $NetBSD: buildlink3.mk,v 1.8.2.1 2012/10/03 12:07:53 spz Exp $

BUILDLINK_TREE+=	cairo-gobject

.if !defined(CAIRO_GOBJECT_BUILDLINK3_MK)
CAIRO_GOBJECT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cairo-gobject+=	cairo-gobject>=1.10.2
BUILDLINK_ABI_DEPENDS.cairo-gobject+=	cairo-gobject>=1.12.2nb3
BUILDLINK_PKGSRCDIR.cairo-gobject?=	../../graphics/cairo-gobject

.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.endif	# CAIRO_GOBJECT_BUILDLINK3_MK

BUILDLINK_TREE+=	-cairo-gobject
