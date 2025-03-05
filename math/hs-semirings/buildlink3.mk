# $NetBSD: buildlink3.mk,v 1.9 2025/03/05 03:39:44 pho Exp $

BUILDLINK_TREE+=	hs-semirings

.if !defined(HS_SEMIRINGS_BUILDLINK3_MK)
HS_SEMIRINGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-semirings+=	hs-semirings>=0.7
BUILDLINK_ABI_DEPENDS.hs-semirings+=	hs-semirings>=0.7nb2
BUILDLINK_PKGSRCDIR.hs-semirings?=	../../math/hs-semirings

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_SEMIRINGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-semirings
