# $NetBSD: buildlink3.mk,v 1.2 2022/01/18 02:48:08 pho Exp $

BUILDLINK_TREE+=	hs-ghc-lib-parser-ex

.if !defined(HS_GHC_LIB_PARSER_EX_BUILDLINK3_MK)
HS_GHC_LIB_PARSER_EX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ghc-lib-parser-ex+=	hs-ghc-lib-parser-ex>=9.0.0
BUILDLINK_ABI_DEPENDS.hs-ghc-lib-parser-ex+=	hs-ghc-lib-parser-ex>=9.0.0.4nb1
BUILDLINK_PKGSRCDIR.hs-ghc-lib-parser-ex?=	../../devel/hs-ghc-lib-parser-ex

.include "../../devel/hs-uniplate/buildlink3.mk"
.endif	# HS_GHC_LIB_PARSER_EX_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ghc-lib-parser-ex
