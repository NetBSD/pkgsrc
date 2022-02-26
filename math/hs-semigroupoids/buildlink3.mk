# $NetBSD: buildlink3.mk,v 1.7 2022/02/26 03:58:18 pho Exp $

BUILDLINK_TREE+=	hs-semigroupoids

.if !defined(HS_SEMIGROUPOIDS_BUILDLINK3_MK)
HS_SEMIGROUPOIDS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-semigroupoids+=	hs-semigroupoids>=5.3.7
BUILDLINK_ABI_DEPENDS.hs-semigroupoids+=	hs-semigroupoids>=5.3.7nb2
BUILDLINK_PKGSRCDIR.hs-semigroupoids?=		../../math/hs-semigroupoids

.include "../../devel/hs-base-orphans/buildlink3.mk"
.include "../../math/hs-bifunctors/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../math/hs-contravariant/buildlink3.mk"
.include "../../math/hs-distributive/buildlink3.mk"
.include "../../math/hs-comonad/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_SEMIGROUPOIDS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-semigroupoids
