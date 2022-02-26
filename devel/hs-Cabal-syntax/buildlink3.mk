# $NetBSD: buildlink3.mk,v 1.3 2022/02/26 03:57:46 pho Exp $

BUILDLINK_TREE+=	hs-Cabal-syntax

.if !defined(HS_CABAL_SYNTAX_BUILDLINK3_MK)
HS_CABAL_SYNTAX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-Cabal-syntax+=	hs-Cabal-syntax>=3.6.0
BUILDLINK_ABI_DEPENDS.hs-Cabal-syntax+=	hs-Cabal-syntax>=3.6.0.0nb2
BUILDLINK_PKGSRCDIR.hs-Cabal-syntax?=	../../devel/hs-Cabal-syntax
.endif	# HS_CABAL_SYNTAX_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-Cabal-syntax
