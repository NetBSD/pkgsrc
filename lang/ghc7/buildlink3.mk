# $NetBSD: buildlink3.mk,v 1.1 2013/12/12 12:47:17 obache Exp $

BUILDLINK_TREE+=	ghc

.if !defined(GHC_BUILDLINK3_MK)
GHC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghc+=	ghc>=7.6.3
BUILDLINK_PKGSRCDIR.ghc?=	../../lang/ghc7

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.endif	# GHC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghc
