# $NetBSD: buildlink3.mk,v 1.7 2020/01/02 04:52:43 pho Exp $

BUILDLINK_TREE+=	hs-haskell-src-exts

.if !defined(HS_HASKELL_SRC_EXTS_BUILDLINK3_MK)
HS_HASKELL_SRC_EXTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-haskell-src-exts+=	hs-haskell-src-exts>=1.22.0
BUILDLINK_ABI_DEPENDS.hs-haskell-src-exts+=	hs-haskell-src-exts>=1.22.0
BUILDLINK_PKGSRCDIR.hs-haskell-src-exts?=	../../devel/hs-haskell-src-exts

.include "../../devel/hs-fail/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.endif	# HS_HASKELL_SRC_EXTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-haskell-src-exts
