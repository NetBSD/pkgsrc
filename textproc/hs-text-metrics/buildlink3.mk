# $NetBSD: buildlink3.mk,v 1.1 2025/03/07 10:43:34 pho Exp $

BUILDLINK_TREE+=	hs-text-metrics

.if !defined(HS_TEXT_METRICS_BUILDLINK3_MK)
HS_TEXT_METRICS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-text-metrics+=	hs-text-metrics>=0.3.3
BUILDLINK_ABI_DEPENDS.hs-text-metrics+=	hs-text-metrics>=0.3.3
BUILDLINK_PKGSRCDIR.hs-text-metrics?=	../../textproc/hs-text-metrics

.include "../../devel/hs-vector/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.endif	# HS_TEXT_METRICS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-text-metrics
