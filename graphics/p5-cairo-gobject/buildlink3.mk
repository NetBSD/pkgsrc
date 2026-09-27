# $NetBSD: buildlink3.mk,v 1.12 2026/09/27 11:36:56 tnn Exp $

BUILDLINK_TREE+=	p5-cairo-gobject

.if !defined(P5_CAIRO_GOBJECT_BUILDLINK3_MK)
P5_CAIRO_GOBJECT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p5-cairo-gobject+=	p5-cairo-gobject>=1.005
BUILDLINK_ABI_DEPENDS.p5-cairo-gobject?=	p5-cairo-gobject>=1.005nb15
BUILDLINK_PKGSRCDIR.p5-cairo-gobject?=	../../graphics/p5-cairo-gobject

.include "../../graphics/cairo/buildlink3.mk"
.endif	# P5_CAIRO_GOBJECT_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-cairo-gobject
