# $NetBSD: buildlink3.mk,v 1.5 2023/02/07 01:40:48 pho Exp $

BUILDLINK_TREE+=	hs-semialign

.if !defined(HS_SEMIALIGN_BUILDLINK3_MK)
HS_SEMIALIGN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-semialign+=	hs-semialign>=1.2.0
BUILDLINK_ABI_DEPENDS.hs-semialign+=	hs-semialign>=1.2.0.1nb4
BUILDLINK_PKGSRCDIR.hs-semialign?=	../../devel/hs-semialign

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-indexed-traversable/buildlink3.mk"
.include "../../devel/hs-indexed-traversable-instances/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-these/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../math/hs-semigroupoids/buildlink3.mk"
.endif	# HS_SEMIALIGN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-semialign
