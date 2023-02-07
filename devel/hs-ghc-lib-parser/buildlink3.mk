# $NetBSD: buildlink3.mk,v 1.4 2023/02/07 01:40:35 pho Exp $

BUILDLINK_TREE+=	hs-ghc-lib-parser

.if !defined(HS_GHC_LIB_PARSER_BUILDLINK3_MK)
HS_GHC_LIB_PARSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ghc-lib-parser+=	hs-ghc-lib-parser>=9.4.4
BUILDLINK_ABI_DEPENDS.hs-ghc-lib-parser+=	hs-ghc-lib-parser>=9.4.4.20221225nb1
BUILDLINK_PKGSRCDIR.hs-ghc-lib-parser?=		../../devel/hs-ghc-lib-parser
.endif	# HS_GHC_LIB_PARSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ghc-lib-parser
