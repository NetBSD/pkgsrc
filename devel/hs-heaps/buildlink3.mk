# $NetBSD: buildlink3.mk,v 1.2 2025/02/02 13:05:09 pho Exp $

BUILDLINK_TREE+=	hs-heaps

.if !defined(HS_HEAPS_BUILDLINK3_MK)
HS_HEAPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-heaps+=	hs-heaps>=0.4.1
BUILDLINK_ABI_DEPENDS.hs-heaps+=	hs-heaps>=0.4.1nb1
BUILDLINK_PKGSRCDIR.hs-heaps?=		../../devel/hs-heaps

.endif	# HS_HEAPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-heaps
