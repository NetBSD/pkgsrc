# $NetBSD: buildlink3.mk,v 1.11 2024/05/09 01:32:48 pho Exp $

BUILDLINK_TREE+=	hs-text-short

.if !defined(HS_TEXT_SHORT_BUILDLINK3_MK)
HS_TEXT_SHORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-text-short+=	hs-text-short>=0.1.5
BUILDLINK_ABI_DEPENDS.hs-text-short+=	hs-text-short>=0.1.5nb6
BUILDLINK_PKGSRCDIR.hs-text-short?=	../../textproc/hs-text-short

.include "../../devel/hs-hashable/buildlink3.mk"
.endif	# HS_TEXT_SHORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-text-short
