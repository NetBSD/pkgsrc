# $NetBSD: buildlink3.mk,v 1.19 2018/11/14 22:21:35 kleink Exp $

BUILDLINK_TREE+=	cairo-gobject

.if !defined(CAIRO_GOBJECT_BUILDLINK3_MK)
CAIRO_GOBJECT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cairo-gobject+=	cairo-gobject>=1.10.2
BUILDLINK_ABI_DEPENDS.cairo-gobject+=	cairo-gobject>=1.16.0nb2
BUILDLINK_PKGSRCDIR.cairo-gobject?=	../../graphics/cairo-gobject

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.endif	# CAIRO_GOBJECT_BUILDLINK3_MK

BUILDLINK_TREE+=	-cairo-gobject
