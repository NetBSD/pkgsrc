# $NetBSD: buildlink3.mk,v 1.3 2023/02/07 01:41:08 pho Exp $

BUILDLINK_TREE+=	hs-boxes

.if !defined(HS_BOXES_BUILDLINK3_MK)
HS_BOXES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-boxes+=	hs-boxes>=0.1.5
BUILDLINK_ABI_DEPENDS.hs-boxes+=	hs-boxes>=0.1.5nb2
BUILDLINK_PKGSRCDIR.hs-boxes?=		../../textproc/hs-boxes

.include "../../devel/hs-split/buildlink3.mk"
.endif	# HS_BOXES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-boxes
