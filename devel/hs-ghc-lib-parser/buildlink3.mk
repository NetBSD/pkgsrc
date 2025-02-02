# $NetBSD: buildlink3.mk,v 1.13 2025/02/02 13:05:07 pho Exp $

BUILDLINK_TREE+=	hs-ghc-lib-parser

.if !defined(HS_GHC_LIB_PARSER_BUILDLINK3_MK)
HS_GHC_LIB_PARSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ghc-lib-parser+=	hs-ghc-lib-parser>=9.10.1
BUILDLINK_ABI_DEPENDS.hs-ghc-lib-parser+=	hs-ghc-lib-parser>=9.10.1.20250103nb1
BUILDLINK_PKGSRCDIR.hs-ghc-lib-parser?=		../../devel/hs-ghc-lib-parser
.endif	# HS_GHC_LIB_PARSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ghc-lib-parser
