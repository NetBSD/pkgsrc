# $NetBSD: buildlink3.mk,v 1.8 2025/01/31 09:05:38 pho Exp $

BUILDLINK_TREE+=	hs-entropy

.if !defined(HS_ENTROPY_BUILDLINK3_MK)
HS_ENTROPY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-entropy+=	hs-entropy>=0.4.1
BUILDLINK_ABI_DEPENDS.hs-entropy+=	hs-entropy>=0.4.1.11
BUILDLINK_PKGSRCDIR.hs-entropy?=	../../security/hs-entropy
.endif	# HS_ENTROPY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-entropy
