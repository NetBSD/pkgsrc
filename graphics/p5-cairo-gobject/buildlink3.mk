# $NetBSD: buildlink3.mk,v 1.7 2023/11/14 14:02:09 wiz Exp $

BUILDLINK_TREE+=	p5-cairo-gobject

.if !defined(P5_CAIRO_GOBJECT_BUILDLINK3_MK)
P5_CAIRO_GOBJECT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p5-cairo-gobject+=	p5-cairo-gobject>=1.005
BUILDLINK_ABI_DEPENDS.p5-cairo-gobject?=	p5-cairo-gobject>=1.005nb7
BUILDLINK_PKGSRCDIR.p5-cairo-gobject?=	../../graphics/p5-cairo-gobject

.include "../../graphics/cairo/buildlink3.mk"
.endif	# P5_CAIRO_GOBJECT_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-cairo-gobject
