# $NetBSD: buildlink3.mk,v 1.7 2024/05/09 01:32:05 pho Exp $

BUILDLINK_TREE+=	hs-monoidal-containers

.if !defined(HS_MONOIDAL_CONTAINERS_BUILDLINK3_MK)
HS_MONOIDAL_CONTAINERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-monoidal-containers+=	hs-monoidal-containers>=0.6.4
BUILDLINK_ABI_DEPENDS.hs-monoidal-containers+=	hs-monoidal-containers>=0.6.4.0nb2
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
