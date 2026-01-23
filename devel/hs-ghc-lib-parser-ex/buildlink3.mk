# $NetBSD: buildlink3.mk,v 1.17 2026/01/23 21:42:01 wiz Exp $

BUILDLINK_TREE+=	hs-ghc-lib-parser-ex

.if !defined(HS_GHC_LIB_PARSER_EX_BUILDLINK3_MK)
HS_GHC_LIB_PARSER_EX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ghc-lib-parser-ex+=	hs-ghc-lib-parser-ex>=9.14.2
BUILDLINK_ABI_DEPENDS.hs-ghc-lib-parser-ex+=	hs-ghc-lib-parser-ex>=9.14.2.0
BUILDLINK_PKGSRCDIR.hs-ghc-lib-parser-ex?=	../../devel/hs-ghc-lib-parser-ex

.include "../../devel/hs-ghc-lib-parser/buildlink3.mk"
.include "../../devel/hs-uniplate/buildlink3.mk"
.endif	# HS_GHC_LIB_PARSER_EX_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ghc-lib-parser-ex
