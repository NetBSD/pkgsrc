# $NetBSD: buildlink3.mk,v 1.7 2023/11/02 06:36:31 pho Exp $

BUILDLINK_TREE+=	hs-ghc-exactprint

.if !defined(HS_GHC_EXACTPRINT_BUILDLINK3_MK)
HS_GHC_EXACTPRINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ghc-exactprint+=	hs-ghc-exactprint>=1.7.0
BUILDLINK_ABI_DEPENDS.hs-ghc-exactprint+=	hs-ghc-exactprint>=1.7.0.1nb1
BUILDLINK_PKGSRCDIR.hs-ghc-exactprint?=		../../devel/hs-ghc-exactprint

.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../devel/hs-fail/buildlink3.mk"
.include "../../math/hs-free/buildlink3.mk"
.include "../../devel/hs-ordered-containers/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.endif	# HS_GHC_EXACTPRINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ghc-exactprint
