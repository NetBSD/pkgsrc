# $NetBSD: buildlink3.mk,v 1.7 2024/05/09 01:32:24 pho Exp $

BUILDLINK_TREE+=	hs-adjunctions

.if !defined(HS_ADJUNCTIONS_BUILDLINK3_MK)
HS_ADJUNCTIONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-adjunctions+=	hs-adjunctions>=4.4.2
BUILDLINK_ABI_DEPENDS.hs-adjunctions+=	hs-adjunctions>=4.4.2nb4
BUILDLINK_PKGSRCDIR.hs-adjunctions?=	../../math/hs-adjunctions

.include "../../math/hs-comonad/buildlink3.mk"
.include "../../math/hs-contravariant/buildlink3.mk"
.include "../../math/hs-distributive/buildlink3.mk"
.include "../../math/hs-free/buildlink3.mk"
.include "../../math/hs-profunctors/buildlink3.mk"
.include "../../math/hs-semigroupoids/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../devel/hs-void/buildlink3.mk"
.endif	# HS_ADJUNCTIONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-adjunctions
