# $NetBSD: buildlink3.mk,v 1.10 2026/11/13 14:39:35 pho Exp $

BUILDLINK_TREE+=	hs-primes

.if !defined(HS_PRIMES_BUILDLINK3_MK)
HS_PRIMES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-primes+=	hs-primes>=0.2.1
BUILDLINK_ABI_DEPENDS.hs-primes+=	hs-primes>=0.2.1.0nb9
BUILDLINK_PKGSRCDIR.hs-primes?=		../../math/hs-primes
.endif	# HS_PRIMES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-primes
