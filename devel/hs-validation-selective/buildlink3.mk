# $NetBSD: buildlink3.mk,v 1.5 2025/08/13 11:07:05 pho Exp $

BUILDLINK_TREE+=	hs-validation-selective

.if !defined(HS_VALIDATION_SELECTIVE_BUILDLINK3_MK)
HS_VALIDATION_SELECTIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-validation-selective+=	hs-validation-selective>=0.2.0
BUILDLINK_ABI_DEPENDS.hs-validation-selective+=	hs-validation-selective>=0.2.0.0nb4
BUILDLINK_PKGSRCDIR.hs-validation-selective?=	../../devel/hs-validation-selective

.include "../../devel/hs-selective/buildlink3.mk"
.endif	# HS_VALIDATION_SELECTIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-validation-selective
