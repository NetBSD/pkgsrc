# $NetBSD: buildlink3.mk,v 1.7 2025/03/05 03:40:04 pho Exp $

BUILDLINK_TREE+=	hs-text-builder-linear

.if !defined(HS_TEXT_BUILDER_LINEAR_BUILDLINK3_MK)
HS_TEXT_BUILDER_LINEAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-text-builder-linear+=	hs-text-builder-linear>=0.1.3
BUILDLINK_ABI_DEPENDS.hs-text-builder-linear+=	hs-text-builder-linear>=0.1.3nb2
BUILDLINK_PKGSRCDIR.hs-text-builder-linear?=	../../textproc/hs-text-builder-linear

.include "../../math/hs-quote-quot/buildlink3.mk"
.endif	# HS_TEXT_BUILDER_LINEAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-text-builder-linear
