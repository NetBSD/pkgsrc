# $NetBSD: buildlink3.mk,v 1.1 2020/01/03 04:36:38 pho Exp $

BUILDLINK_TREE+=	hs-comonad

.if !defined(HS_COMONAD_BUILDLINK3_MK)
HS_COMONAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-comonad+=	hs-comonad>=5.0.6
BUILDLINK_ABI_DEPENDS.hs-comonad+=	hs-comonad>=5.0.6
BUILDLINK_PKGSRCDIR.hs-comonad?=	../../math/hs-comonad

.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.include "../../math/hs-distributive/buildlink3.mk"
.endif	# HS_COMONAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-comonad
