# $NetBSD: buildlink3.mk,v 1.4 2023/02/07 01:41:00 pho Exp $

BUILDLINK_TREE+=	hs-kan-extensions

.if !defined(HS_KAN_EXTENSIONS_BUILDLINK3_MK)
HS_KAN_EXTENSIONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-kan-extensions+=	hs-kan-extensions>=5.2.5
BUILDLINK_ABI_DEPENDS.hs-kan-extensions+=	hs-kan-extensions>=5.2.5nb1
BUILDLINK_PKGSRCDIR.hs-kan-extensions?=		../../math/hs-kan-extensions

.include "../../math/hs-adjunctions/buildlink3.mk"
.include "../../math/hs-comonad/buildlink3.mk"
.include "../../math/hs-contravariant/buildlink3.mk"
.include "../../math/hs-distributive/buildlink3.mk"
.include "../../math/hs-free/buildlink3.mk"
.include "../../math/hs-invariant/buildlink3.mk"
.include "../../math/hs-profunctors/buildlink3.mk"
.include "../../math/hs-semigroupoids/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.endif	# HS_KAN_EXTENSIONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-kan-extensions
