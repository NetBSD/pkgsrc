# $NetBSD: buildlink3.mk,v 1.5 2025/02/02 13:04:50 pho Exp $

BUILDLINK_TREE+=	hs-criterion-measurement

.if !defined(HS_CRITERION_MEASUREMENT_BUILDLINK3_MK)
HS_CRITERION_MEASUREMENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-criterion-measurement+=	hs-criterion-measurement>=0.2.3
BUILDLINK_ABI_DEPENDS.hs-criterion-measurement+=	hs-criterion-measurement>=0.2.3.0nb1
BUILDLINK_PKGSRCDIR.hs-criterion-measurement?=		../../benchmarks/hs-criterion-measurement

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-base-compat/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_CRITERION_MEASUREMENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-criterion-measurement
