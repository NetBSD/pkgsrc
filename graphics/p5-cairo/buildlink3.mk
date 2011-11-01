# $NetBSD: buildlink3.mk,v 1.6 2011/11/01 06:01:42 sbd Exp $

BUILDLINK_TREE+=	p5-cairo

.if !defined(P5_CAIRO_BUILDLINK3_MK)
P5_CAIRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p5-cairo+=	p5-cairo>=1.023
BUILDLINK_ABI_DEPENDS.p5-cairo?=	p5-cairo>=1.062nb1
BUILDLINK_PKGSRCDIR.p5-cairo?=	../../graphics/p5-cairo

.include "../../graphics/cairo/buildlink3.mk"
.endif # P5_CAIRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-cairo
