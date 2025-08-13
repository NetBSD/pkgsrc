# $NetBSD: buildlink3.mk,v 1.2 2025/08/13 11:06:46 pho Exp $

BUILDLINK_TREE+=	hs-infer-license

.if !defined(HS_INFER_LICENSE_BUILDLINK3_MK)
HS_INFER_LICENSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-infer-license+=	hs-infer-license>=0.2.0
BUILDLINK_ABI_DEPENDS.hs-infer-license+=	hs-infer-license>=0.2.0nb1
BUILDLINK_PKGSRCDIR.hs-infer-license?=		../../devel/hs-infer-license

.include "../../textproc/hs-text-metrics/buildlink3.mk"
.endif	# HS_INFER_LICENSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-infer-license
