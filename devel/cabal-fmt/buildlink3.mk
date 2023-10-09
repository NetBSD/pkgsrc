# $NetBSD: buildlink3.mk,v 1.3 2023/10/09 04:54:04 pho Exp $

BUILDLINK_TREE+=	cabal-fmt

.if !defined(CABAL_FMT_BUILDLINK3_MK)
CABAL_FMT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cabal-fmt+=	cabal-fmt>=0.1.6
BUILDLINK_ABI_DEPENDS.cabal-fmt+=	cabal-fmt>=0.1.6nb2
BUILDLINK_PKGSRCDIR.cabal-fmt?=		../../devel/cabal-fmt
.endif	# CABAL_FMT_BUILDLINK3_MK

BUILDLINK_TREE+=	-cabal-fmt
