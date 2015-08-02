# $NetBSD: buildlink3.mk,v 1.3 2015/08/02 11:37:31 szptvlfn Exp $

BUILDLINK_TREE+=	hs-haskell-src-exts

.if !defined(HS_HASKELL_SRC_EXTS_BUILDLINK3_MK)
HS_HASKELL_SRC_EXTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-haskell-src-exts+=	hs-haskell-src-exts>=1.16.0
BUILDLINK_ABI_DEPENDS.hs-haskell-src-exts+=	hs-haskell-src-exts>=1.16.0.1nb2
BUILDLINK_PKGSRCDIR.hs-haskell-src-exts?=	../../devel/hs-haskell-src-exts

.include "../../devel/hs-cpphs/buildlink3.mk"
.endif	# HS_HASKELL_SRC_EXTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-haskell-src-exts
