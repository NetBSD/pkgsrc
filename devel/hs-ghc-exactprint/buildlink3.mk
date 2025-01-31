# $NetBSD: buildlink3.mk,v 1.11 2025/01/31 15:11:38 pho Exp $

BUILDLINK_TREE+=	hs-ghc-exactprint

.if !defined(HS_GHC_EXACTPRINT_BUILDLINK3_MK)
HS_GHC_EXACTPRINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ghc-exactprint+=	hs-ghc-exactprint>=1.9.0
BUILDLINK_ABI_DEPENDS.hs-ghc-exactprint+=	hs-ghc-exactprint>=1.9.0.0
BUILDLINK_PKGSRCDIR.hs-ghc-exactprint?=		../../devel/hs-ghc-exactprint

.include "../../devel/hs-syb/buildlink3.mk"
.endif	# HS_GHC_EXACTPRINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ghc-exactprint
