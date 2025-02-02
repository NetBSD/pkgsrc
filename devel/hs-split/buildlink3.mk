# $NetBSD: buildlink3.mk,v 1.17 2025/02/02 13:05:23 pho Exp $

BUILDLINK_TREE+=	hs-split

.if !defined(HS_SPLIT_BUILDLINK3_MK)
HS_SPLIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-split+=	hs-split>=0.2.5
BUILDLINK_ABI_DEPENDS.hs-split+=	hs-split>=0.2.5nb2
BUILDLINK_PKGSRCDIR.hs-split?=		../../devel/hs-split
.endif	# HS_SPLIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-split
