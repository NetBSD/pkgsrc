# $NetBSD: buildlink3.mk,v 1.1 2014/09/10 21:40:07 szptvlfn Exp $

BUILDLINK_TREE+=	hs-ghc-mtl

.if !defined(HS_GHC_MTL_BUILDLINK3_MK)
HS_GHC_MTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ghc-mtl+=	hs-ghc-mtl>=1.2.1
BUILDLINK_ABI_DEPENDS.hs-ghc-mtl+=	hs-ghc-mtl>=1.2.1.0
BUILDLINK_PKGSRCDIR.hs-ghc-mtl?=	../../devel/hs-ghc-mtl

.include "../../devel/hs-exceptions/buildlink3.mk"
.include "../../devel/hs-extensible-exceptions/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.endif	# HS_GHC_MTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ghc-mtl
