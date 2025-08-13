# $NetBSD: buildlink3.mk,v 1.2 2025/08/13 11:07:20 pho Exp $

BUILDLINK_TREE+=	hs-blake2

.if !defined(HS_BLAKE2_BUILDLINK3_MK)
HS_BLAKE2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-blake2+=	hs-blake2>=0.3.0
BUILDLINK_ABI_DEPENDS.hs-blake2+=	hs-blake2>=0.3.0.1nb1
BUILDLINK_PKGSRCDIR.hs-blake2?=		../../security/hs-blake2

.endif	# HS_BLAKE2_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-blake2
