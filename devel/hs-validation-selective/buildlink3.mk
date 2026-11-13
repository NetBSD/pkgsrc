# $NetBSD: buildlink3.mk,v 1.6 2026/11/13 14:39:25 pho Exp $

BUILDLINK_TREE+=	hs-validation-selective

.if !defined(HS_VALIDATION_SELECTIVE_BUILDLINK3_MK)
HS_VALIDATION_SELECTIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-validation-selective+=	hs-validation-selective>=0.2.0
BUILDLINK_ABI_DEPENDS.hs-validation-selective+=	hs-validation-selective>=0.2.0.0nb5
BUILDLINK_PKGSRCDIR.hs-validation-selective?=	../../devel/hs-validation-selective

.include "../../devel/hs-selective/buildlink3.mk"
.endif	# HS_VALIDATION_SELECTIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-validation-selective
