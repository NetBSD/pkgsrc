# $NetBSD: buildlink3.mk,v 1.5 2023/11/02 06:37:15 pho Exp $

BUILDLINK_TREE+=	hs-semirings

.if !defined(HS_SEMIRINGS_BUILDLINK3_MK)
HS_SEMIRINGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-semirings+=	hs-semirings>=0.6
BUILDLINK_ABI_DEPENDS.hs-semirings+=	hs-semirings>=0.6nb4
BUILDLINK_PKGSRCDIR.hs-semirings?=	../../math/hs-semirings

.include "../../devel/hs-base-compat-batteries/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_SEMIRINGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-semirings
