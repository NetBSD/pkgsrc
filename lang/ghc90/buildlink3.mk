# $NetBSD: buildlink3.mk,v 1.5 2022/01/18 02:22:49 pho Exp $

BUILDLINK_TREE+=	ghc

.if !defined(GHC_BUILDLINK3_MK)
GHC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghc+=	ghc>=9.0
BUILDLINK_ABI_DEPENDS.ghc+=	ghc>=9.0.2
BUILDLINK_PKGSRCDIR.ghc?=	../../lang/ghc90

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.endif	# GHC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghc
