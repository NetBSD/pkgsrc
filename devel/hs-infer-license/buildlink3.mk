# $NetBSD: buildlink3.mk,v 1.3 2026/11/13 14:39:04 pho Exp $

BUILDLINK_TREE+=	hs-infer-license

.if !defined(HS_INFER_LICENSE_BUILDLINK3_MK)
HS_INFER_LICENSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-infer-license+=	hs-infer-license>=0.2.0
BUILDLINK_ABI_DEPENDS.hs-infer-license+=	hs-infer-license>=0.2.0nb2
BUILDLINK_PKGSRCDIR.hs-infer-license?=		../../devel/hs-infer-license

.include "../../textproc/hs-text-metrics/buildlink3.mk"
.endif	# HS_INFER_LICENSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-infer-license
