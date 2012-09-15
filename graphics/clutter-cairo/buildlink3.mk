# $NetBSD: buildlink3.mk,v 1.14 2012/09/15 10:04:47 obache Exp $
#

BUILDLINK_TREE+=	clutter-cairo

.if !defined(CLUTTER_CAIRO_BUILDLINK3_MK)
CLUTTER_CAIRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clutter-cairo+=	clutter-cairo>=0.8.0
BUILDLINK_ABI_DEPENDS.clutter-cairo+=	clutter-cairo>=0.8.2nb12
BUILDLINK_PKGSRCDIR.clutter-cairo?=	../../graphics/clutter-cairo

.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/clutter08/buildlink3.mk"
.endif # CLUTTER_CAIRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-clutter-cairo
