# $NetBSD: buildlink3.mk,v 1.3 2020/03/08 16:42:27 bsiegert Exp $

BUILDLINK_TREE+=	ghc

.if !defined(GHC_BUILDLINK3_MK)
GHC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghc+=	ghc>=8.4.4
BUILDLINK_ABI_DEPENDS.ghc+=	ghc>=8.4.4nb1
BUILDLINK_PKGSRCDIR.ghc?=	../../lang/ghc84

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.endif	# GHC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghc
