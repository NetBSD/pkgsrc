# $NetBSD: buildlink3.mk,v 1.7 2022/01/18 02:48:12 pho Exp $

BUILDLINK_TREE+=	hs-split

.if !defined(HS_SPLIT_BUILDLINK3_MK)
HS_SPLIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-split+=	hs-split>=0.2.3.4
BUILDLINK_ABI_DEPENDS.hs-split+=	hs-split>=0.2.3.4nb2
BUILDLINK_PKGSRCDIR.hs-split?=		../../devel/hs-split
.endif	# HS_SPLIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-split
