# $NetBSD: buildlink3.mk,v 1.19 2022/06/28 11:33:39 wiz Exp $

BUILDLINK_TREE+=	p5-glib2

.if !defined(P5_GLIB2_BUILDLINK3_MK)
P5_GLIB2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p5-glib2+=	p5-glib2>=1.103
BUILDLINK_ABI_DEPENDS.p5-glib2+=	p5-glib2>=1.3293nb3
BUILDLINK_PKGSRCDIR.p5-glib2?=		../../devel/p5-glib2

.include "../../devel/glib2/buildlink3.mk"
.endif # P5_GLIB2_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-glib2
