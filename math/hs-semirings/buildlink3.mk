# $NetBSD: buildlink3.mk,v 1.7 2025/01/31 08:08:47 pho Exp $

BUILDLINK_TREE+=	hs-semirings

.if !defined(HS_SEMIRINGS_BUILDLINK3_MK)
HS_SEMIRINGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-semirings+=	hs-semirings>=0.7
BUILDLINK_ABI_DEPENDS.hs-semirings+=	hs-semirings>=0.7
BUILDLINK_PKGSRCDIR.hs-semirings?=	../../math/hs-semirings

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_SEMIRINGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-semirings
