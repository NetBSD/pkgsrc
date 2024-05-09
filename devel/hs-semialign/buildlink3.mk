# $NetBSD: buildlink3.mk,v 1.9 2024/05/09 01:32:11 pho Exp $

BUILDLINK_TREE+=	hs-semialign

.if !defined(HS_SEMIALIGN_BUILDLINK3_MK)
HS_SEMIALIGN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-semialign+=	hs-semialign>=1.3
BUILDLINK_ABI_DEPENDS.hs-semialign+=	hs-semialign>=1.3nb2
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
