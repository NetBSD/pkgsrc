# $NetBSD: buildlink3.mk,v 1.2 2022/02/26 03:58:00 pho Exp $

BUILDLINK_TREE+=	hs-keys

.if !defined(HS_KEYS_BUILDLINK3_MK)
HS_KEYS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-keys+=	hs-keys>=3.12.3
BUILDLINK_ABI_DEPENDS.hs-keys+=	hs-keys>=3.12.3nb1
BUILDLINK_PKGSRCDIR.hs-keys?=	../../devel/hs-keys

.include "../../math/hs-comonad/buildlink3.mk"
.include "../../math/hs-free/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../math/hs-semigroupoids/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_KEYS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-keys
