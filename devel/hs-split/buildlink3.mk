# $NetBSD: buildlink3.mk,v 1.11 2023/02/07 01:40:49 pho Exp $

BUILDLINK_TREE+=	hs-split

.if !defined(HS_SPLIT_BUILDLINK3_MK)
HS_SPLIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-split+=	hs-split>=0.2.3
BUILDLINK_ABI_DEPENDS.hs-split+=	hs-split>=0.2.3.5nb1
BUILDLINK_PKGSRCDIR.hs-split?=		../../devel/hs-split
.endif	# HS_SPLIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-split
