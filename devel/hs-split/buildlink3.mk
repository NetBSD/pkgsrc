# $NetBSD: buildlink3.mk,v 1.14 2023/11/02 06:36:57 pho Exp $

BUILDLINK_TREE+=	hs-split

.if !defined(HS_SPLIT_BUILDLINK3_MK)
HS_SPLIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-split+=	hs-split>=0.2.4
BUILDLINK_ABI_DEPENDS.hs-split+=	hs-split>=0.2.4nb1
BUILDLINK_PKGSRCDIR.hs-split?=		../../devel/hs-split
.endif	# HS_SPLIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-split
