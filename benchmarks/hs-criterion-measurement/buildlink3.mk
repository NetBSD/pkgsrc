# $NetBSD: buildlink3.mk,v 1.3 2024/05/09 01:31:39 pho Exp $

BUILDLINK_TREE+=	hs-criterion-measurement

.if !defined(HS_CRITERION_MEASUREMENT_BUILDLINK3_MK)
HS_CRITERION_MEASUREMENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-criterion-measurement+=	hs-criterion-measurement>=0.2.1
BUILDLINK_ABI_DEPENDS.hs-criterion-measurement+=	hs-criterion-measurement>=0.2.1.0nb2
BUILDLINK_PKGSRCDIR.hs-criterion-measurement?=		../../benchmarks/hs-criterion-measurement

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-base-compat/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_CRITERION_MEASUREMENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-criterion-measurement
