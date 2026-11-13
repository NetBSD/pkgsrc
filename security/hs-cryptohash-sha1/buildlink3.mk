# $NetBSD: buildlink3.mk,v 1.10 2026/11/13 14:39:41 pho Exp $

BUILDLINK_TREE+=	hs-cryptohash-sha1

.if !defined(HS_CRYPTOHASH_SHA1_BUILDLINK3_MK)
HS_CRYPTOHASH_SHA1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cryptohash-sha1+=	hs-cryptohash-sha1>=0.11.101
BUILDLINK_ABI_DEPENDS.hs-cryptohash-sha1+=	hs-cryptohash-sha1>=0.11.101.0nb9
BUILDLINK_PKGSRCDIR.hs-cryptohash-sha1?=	../../security/hs-cryptohash-sha1
.endif	# HS_CRYPTOHASH_SHA1_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cryptohash-sha1
