# $NetBSD: buildlink3.mk,v 1.8 2024/05/09 01:32:01 pho Exp $

BUILDLINK_TREE+=	hs-lens

.if !defined(HS_LENS_BUILDLINK3_MK)
HS_LENS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-lens+=	hs-lens>=5.2
BUILDLINK_ABI_DEPENDS.hs-lens+=	hs-lens>=5.2.3nb2
BUILDLINK_PKGSRCDIR.hs-lens?=	../../devel/hs-lens

.include "../../devel/hs-assoc/buildlink3.mk"
.include "../../devel/hs-base-orphans/buildlink3.mk"
.include "../../math/hs-bifunctors/buildlink3.mk"
.include "../../devel/hs-call-stack/buildlink3.mk"
.include "../../math/hs-comonad/buildlink3.mk"
.include "../../math/hs-contravariant/buildlink3.mk"
.include "../../math/hs-distributive/buildlink3.mk"
.include "../../math/hs-free/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-indexed-traversable/buildlink3.mk"
.include "../../devel/hs-indexed-traversable-instances/buildlink3.mk"
.include "../../math/hs-kan-extensions/buildlink3.mk"
.include "../../devel/hs-parallel/buildlink3.mk"
.include "../../math/hs-profunctors/buildlink3.mk"
.include "../../devel/hs-reflection/buildlink3.mk"
.include "../../math/hs-semigroupoids/buildlink3.mk"
.include "../../devel/hs-strict/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-th-abstraction/buildlink3.mk"
.include "../../devel/hs-these/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_LENS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-lens
