# $NetBSD: buildlink3.mk,v 1.12 2024/05/09 01:32:49 pho Exp $

BUILDLINK_TREE+=	hs-unicode-transforms

.if !defined(HS_UNICODE_TRANSFORMS_BUILDLINK3_MK)
HS_UNICODE_TRANSFORMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-unicode-transforms+=	hs-unicode-transforms>=0.4.0
BUILDLINK_ABI_DEPENDS.hs-unicode-transforms+=	hs-unicode-transforms>=0.4.0.1nb4
BUILDLINK_PKGSRCDIR.hs-unicode-transforms?=	../../textproc/hs-unicode-transforms

.include "../../textproc/hs-unicode-data/buildlink3.mk"
.endif	# HS_UNICODE_TRANSFORMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-unicode-transforms
