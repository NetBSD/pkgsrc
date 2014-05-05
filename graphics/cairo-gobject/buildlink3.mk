# $NetBSD: buildlink3.mk,v 1.15 2014/05/05 00:47:54 ryoon Exp $

BUILDLINK_TREE+=	cairo-gobject

.if !defined(CAIRO_GOBJECT_BUILDLINK3_MK)
CAIRO_GOBJECT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cairo-gobject+=	cairo-gobject>=1.10.2
BUILDLINK_ABI_DEPENDS.cairo-gobject+=	cairo-gobject>=1.12.16nb1
BUILDLINK_PKGSRCDIR.cairo-gobject?=	../../graphics/cairo-gobject

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.endif	# CAIRO_GOBJECT_BUILDLINK3_MK

BUILDLINK_TREE+=	-cairo-gobject
