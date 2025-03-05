# $NetBSD: buildlink3.mk,v 1.3 2025/03/05 03:39:14 pho Exp $

BUILDLINK_TREE+=	hs-heaps

.if !defined(HS_HEAPS_BUILDLINK3_MK)
HS_HEAPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-heaps+=	hs-heaps>=0.4.1
BUILDLINK_ABI_DEPENDS.hs-heaps+=	hs-heaps>=0.4.1nb2
BUILDLINK_PKGSRCDIR.hs-heaps?=		../../devel/hs-heaps

.endif	# HS_HEAPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-heaps
