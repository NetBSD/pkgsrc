# $NetBSD: buildlink3.mk,v 1.13 2025/03/05 03:39:41 pho Exp $

BUILDLINK_TREE+=	hs-comonad

.if !defined(HS_COMONAD_BUILDLINK3_MK)
HS_COMONAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-comonad+=	hs-comonad>=5.0.9
BUILDLINK_ABI_DEPENDS.hs-comonad+=	hs-comonad>=5.0.9nb2
BUILDLINK_PKGSRCDIR.hs-comonad?=	../../math/hs-comonad

.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../math/hs-distributive/buildlink3.mk"
.include "../../devel/hs-indexed-traversable/buildlink3.mk"
.endif	# HS_COMONAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-comonad
