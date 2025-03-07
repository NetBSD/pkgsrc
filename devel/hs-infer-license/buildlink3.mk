# $NetBSD: buildlink3.mk,v 1.1 2025/03/07 10:48:17 pho Exp $

BUILDLINK_TREE+=	hs-infer-license

.if !defined(HS_INFER_LICENSE_BUILDLINK3_MK)
HS_INFER_LICENSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-infer-license+=	hs-infer-license>=0.2.0
BUILDLINK_ABI_DEPENDS.hs-infer-license+=	hs-infer-license>=0.2.0
BUILDLINK_PKGSRCDIR.hs-infer-license?=		../../devel/hs-infer-license

.include "../../textproc/hs-text-metrics/buildlink3.mk"
.endif	# HS_INFER_LICENSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-infer-license
