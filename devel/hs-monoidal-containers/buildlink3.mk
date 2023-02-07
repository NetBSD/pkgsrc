# $NetBSD: buildlink3.mk,v 1.3 2023/02/07 01:40:45 pho Exp $

BUILDLINK_TREE+=	hs-monoidal-containers

.if !defined(HS_MONOIDAL_CONTAINERS_BUILDLINK3_MK)
HS_MONOIDAL_CONTAINERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-monoidal-containers+=	hs-monoidal-containers>=0.6.3
BUILDLINK_ABI_DEPENDS.hs-monoidal-containers+=	hs-monoidal-containers>=0.6.3.0nb1
BUILDLINK_PKGSRCDIR.hs-monoidal-containers?=	../../devel/hs-monoidal-containers

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-newtype/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-witherable/buildlink3.mk"
.include "../../devel/hs-semialign/buildlink3.mk"
.include "../../devel/hs-these/buildlink3.mk"
.endif	# HS_MONOIDAL_CONTAINERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-monoidal-containers
