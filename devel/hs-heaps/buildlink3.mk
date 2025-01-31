# $NetBSD: buildlink3.mk,v 1.1 2025/01/31 14:30:33 pho Exp $

BUILDLINK_TREE+=	hs-heaps

.if !defined(HS_HEAPS_BUILDLINK3_MK)
HS_HEAPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-heaps+=	hs-heaps>=0.4.1
BUILDLINK_ABI_DEPENDS.hs-heaps+=	hs-heaps>=0.4.1
BUILDLINK_PKGSRCDIR.hs-heaps?=		../../devel/hs-heaps

.endif	# HS_HEAPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-heaps
