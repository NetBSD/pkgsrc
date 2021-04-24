# $NetBSD: buildlink3.mk,v 1.2 2021/04/24 13:25:14 pho Exp $

BUILDLINK_TREE+=	hs-cryptohash-sha256

.if !defined(HS_CRYPTOHASH_SHA256_BUILDLINK3_MK)
HS_CRYPTOHASH_SHA256_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cryptohash-sha256+=	hs-cryptohash-sha256>=0.11.102
BUILDLINK_ABI_DEPENDS.hs-cryptohash-sha256+=	hs-cryptohash-sha256>=0.11.102.0
BUILDLINK_PKGSRCDIR.hs-cryptohash-sha256?=	../../security/hs-cryptohash-sha256
.endif	# HS_CRYPTOHASH_SHA256_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cryptohash-sha256
