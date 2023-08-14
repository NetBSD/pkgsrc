# $NetBSD: buildlink3.mk,v 1.7 2023/08/14 05:24:43 wiz Exp $

BUILDLINK_TREE+=	ghc

.if !defined(GHC_BUILDLINK3_MK)
GHC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghc+=	ghc>=9.0
BUILDLINK_ABI_DEPENDS.ghc+=	ghc>=9.0.2nb3
BUILDLINK_PKGSRCDIR.ghc?=	../../lang/ghc90

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.endif	# GHC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghc
