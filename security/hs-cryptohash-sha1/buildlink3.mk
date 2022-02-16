# $NetBSD: buildlink3.mk,v 1.1 2022/02/16 03:31:53 pho Exp $

BUILDLINK_TREE+=	hs-cryptohash-sha1

.if !defined(HS_CRYPTOHASH_SHA1_BUILDLINK3_MK)
HS_CRYPTOHASH_SHA1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cryptohash-sha1+=	hs-cryptohash-sha1>=0.11.101
BUILDLINK_ABI_DEPENDS.hs-cryptohash-sha1+=	hs-cryptohash-sha1>=0.11.101.0
BUILDLINK_PKGSRCDIR.hs-cryptohash-sha1?=	../../security/hs-cryptohash-sha1
.endif	# HS_CRYPTOHASH_SHA1_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cryptohash-sha1
