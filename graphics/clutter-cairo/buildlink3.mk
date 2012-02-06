# $NetBSD: buildlink3.mk,v 1.11 2012/02/06 12:40:18 wiz Exp $
#

BUILDLINK_TREE+=	clutter-cairo

.if !defined(CLUTTER_CAIRO_BUILDLINK3_MK)
CLUTTER_CAIRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clutter-cairo+=	clutter-cairo>=0.8.0
BUILDLINK_ABI_DEPENDS.clutter-cairo+=	clutter-cairo>=0.8.2nb9
BUILDLINK_PKGSRCDIR.clutter-cairo?=	../../graphics/clutter-cairo

.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/clutter08/buildlink3.mk"
.endif # CLUTTER_CAIRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-clutter-cairo
