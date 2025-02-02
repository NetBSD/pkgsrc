# $NetBSD: buildlink3.mk,v 1.13 2025/02/02 13:05:59 pho Exp $

BUILDLINK_TREE+=	hs-text-short

.if !defined(HS_TEXT_SHORT_BUILDLINK3_MK)
HS_TEXT_SHORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-text-short+=	hs-text-short>=0.1.6
BUILDLINK_ABI_DEPENDS.hs-text-short+=	hs-text-short>=0.1.6nb1
BUILDLINK_PKGSRCDIR.hs-text-short?=	../../textproc/hs-text-short

.include "../../devel/hs-hashable/buildlink3.mk"
.endif	# HS_TEXT_SHORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-text-short
