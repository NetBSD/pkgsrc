# $NetBSD: buildlink3.mk,v 1.5 2022/02/11 09:11:06 pho Exp $

BUILDLINK_TREE+=	hs-cryptohash-sha256

.if !defined(HS_CRYPTOHASH_SHA256_BUILDLINK3_MK)
HS_CRYPTOHASH_SHA256_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cryptohash-sha256+=	hs-cryptohash-sha256>=0.11.102
BUILDLINK_ABI_DEPENDS.hs-cryptohash-sha256+=	hs-cryptohash-sha256>=0.11.102.1
BUILDLINK_PKGSRCDIR.hs-cryptohash-sha256?=	../../security/hs-cryptohash-sha256
.endif	# HS_CRYPTOHASH_SHA256_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cryptohash-sha256
