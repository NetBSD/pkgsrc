# $NetBSD: buildlink3.mk,v 1.4 2025/08/13 11:06:43 pho Exp $

BUILDLINK_TREE+=	hs-heaps

.if !defined(HS_HEAPS_BUILDLINK3_MK)
HS_HEAPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-heaps+=	hs-heaps>=0.4.1
BUILDLINK_ABI_DEPENDS.hs-heaps+=	hs-heaps>=0.4.1nb3
BUILDLINK_PKGSRCDIR.hs-heaps?=		../../devel/hs-heaps

.endif	# HS_HEAPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-heaps
