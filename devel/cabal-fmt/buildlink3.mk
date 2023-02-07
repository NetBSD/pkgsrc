# $NetBSD: buildlink3.mk,v 1.2 2023/02/07 01:40:25 pho Exp $

BUILDLINK_TREE+=	cabal-fmt

.if !defined(CABAL_FMT_BUILDLINK3_MK)
CABAL_FMT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cabal-fmt+=	cabal-fmt>=0.1.6
BUILDLINK_ABI_DEPENDS.cabal-fmt+=	cabal-fmt>=0.1.6nb1
BUILDLINK_PKGSRCDIR.cabal-fmt?=		../../devel/cabal-fmt
.endif	# CABAL_FMT_BUILDLINK3_MK

BUILDLINK_TREE+=	-cabal-fmt
