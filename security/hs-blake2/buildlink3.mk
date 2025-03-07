# $NetBSD: buildlink3.mk,v 1.1 2025/03/07 13:12:09 pho Exp $

BUILDLINK_TREE+=	hs-blake2

.if !defined(HS_BLAKE2_BUILDLINK3_MK)
HS_BLAKE2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-blake2+=	hs-blake2>=0.3.0
BUILDLINK_ABI_DEPENDS.hs-blake2+=	hs-blake2>=0.3.0.1
BUILDLINK_PKGSRCDIR.hs-blake2?=		../../security/hs-blake2

.endif	# HS_BLAKE2_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-blake2
