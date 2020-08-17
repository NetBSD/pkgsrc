# $NetBSD: buildlink3.mk,v 1.31 2020/08/17 20:17:24 leot Exp $

BUILDLINK_TREE+=	p5-pango

.if !defined(P5_PANGO_BUILDLINK3_MK)
P5_PANGO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p5-pango+=	p5-pango>=1.200
BUILDLINK_ABI_DEPENDS.p5-pango+=	p5-pango>=1.227nb12
BUILDLINK_PKGSRCDIR.p5-pango?=		../../devel/p5-pango

.include "../../devel/pango/buildlink3.mk"
.endif # P5_PANGO_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-pango
