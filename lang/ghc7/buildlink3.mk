# $NetBSD: buildlink3.mk,v 1.10 2020/01/13 01:06:52 pho Exp $

BUILDLINK_TREE+=	ghc

.if !defined(GHC_BUILDLINK3_MK)
GHC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghc+=	ghc>=7.10.3
BUILDLINK_ABI_DEPENDS.ghc+=	ghc>=7.10.3
BUILDLINK_PKGSRCDIR.ghc?=	../../lang/ghc7

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.endif	# GHC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghc
