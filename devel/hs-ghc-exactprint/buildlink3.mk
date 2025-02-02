# $NetBSD: buildlink3.mk,v 1.12 2025/02/02 13:05:07 pho Exp $

BUILDLINK_TREE+=	hs-ghc-exactprint

.if !defined(HS_GHC_EXACTPRINT_BUILDLINK3_MK)
HS_GHC_EXACTPRINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ghc-exactprint+=	hs-ghc-exactprint>=1.9.0
BUILDLINK_ABI_DEPENDS.hs-ghc-exactprint+=	hs-ghc-exactprint>=1.9.0.0nb1
BUILDLINK_PKGSRCDIR.hs-ghc-exactprint?=		../../devel/hs-ghc-exactprint

.include "../../devel/hs-syb/buildlink3.mk"
.endif	# HS_GHC_EXACTPRINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ghc-exactprint
