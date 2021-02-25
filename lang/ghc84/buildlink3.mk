# $NetBSD: buildlink3.mk,v 1.4 2021/02/25 10:36:52 nia Exp $

BUILDLINK_TREE+=	ghc

.if !defined(GHC_BUILDLINK3_MK)
GHC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghc+=	ghc>=8.4.4<8.5
BUILDLINK_ABI_DEPENDS.ghc+=	ghc>=8.4.4nb1<8.5
BUILDLINK_PKGSRCDIR.ghc?=	../../lang/ghc84

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.endif	# GHC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghc
