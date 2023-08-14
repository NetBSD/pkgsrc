# $NetBSD: buildlink3.mk,v 1.3 2023/08/14 05:24:44 wiz Exp $

BUILDLINK_TREE+=	ghc

.if !defined(GHC_BUILDLINK3_MK)
GHC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghc+=	ghc>=9.4.4
BUILDLINK_ABI_DEPENDS.ghc+=	ghc>=9.4.4nb3
BUILDLINK_PKGSRCDIR.ghc?=	../../lang/ghc94

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.endif	# GHC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghc
