# $NetBSD: buildlink3.mk,v 1.1 2022/02/16 05:09:18 pho Exp $

BUILDLINK_TREE+=	hs-primes

.if !defined(HS_PRIMES_BUILDLINK3_MK)
HS_PRIMES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-primes+=	hs-primes>=0.2.1
BUILDLINK_ABI_DEPENDS.hs-primes+=	hs-primes>=0.2.1.0
BUILDLINK_PKGSRCDIR.hs-primes?=		../../math/hs-primes
.endif	# HS_PRIMES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-primes
