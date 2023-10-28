# $NetBSD: buildlink3.mk,v 1.6 2023/10/28 04:26:46 pho Exp $

BUILDLINK_TREE+=	hs-ghc-lib-parser

.if !defined(HS_GHC_LIB_PARSER_BUILDLINK3_MK)
HS_GHC_LIB_PARSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ghc-lib-parser+=	hs-ghc-lib-parser>=9.6.3
BUILDLINK_ABI_DEPENDS.hs-ghc-lib-parser+=	hs-ghc-lib-parser>=9.6.3.20231014
BUILDLINK_PKGSRCDIR.hs-ghc-lib-parser?=		../../devel/hs-ghc-lib-parser
.endif	# HS_GHC_LIB_PARSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ghc-lib-parser
