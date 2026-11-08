# $NetBSD: buildlink3.mk,v 1.1 2026/11/08 18:06:54 pho Exp $

BUILDLINK_TREE+=	hs-blake3

.if !defined(HS_BLAKE3_BUILDLINK3_MK)
HS_BLAKE3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-blake3+=	hs-blake3>=0.3.1
BUILDLINK_ABI_DEPENDS.hs-blake3+=	hs-blake3>=0.3.1
BUILDLINK_PKGSRCDIR.hs-blake3?=		../../security/hs-blake3

.include "../../devel/hs-ram/buildlink3.mk"
.endif	# HS_BLAKE3_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-blake3
