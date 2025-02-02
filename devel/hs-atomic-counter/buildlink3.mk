# $NetBSD: buildlink3.mk,v 1.2 2025/02/02 13:04:57 pho Exp $

BUILDLINK_TREE+=	hs-atomic-counter

.if !defined(HS_ATOMIC_COUNTER_BUILDLINK3_MK)
HS_ATOMIC_COUNTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-atomic-counter+=	hs-atomic-counter>=0.1.2
BUILDLINK_ABI_DEPENDS.hs-atomic-counter+=	hs-atomic-counter>=0.1.2.3nb1
BUILDLINK_PKGSRCDIR.hs-atomic-counter?=		../../devel/hs-atomic-counter

.endif	# HS_ATOMIC_COUNTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-atomic-counter
