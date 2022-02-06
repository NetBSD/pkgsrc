# $NetBSD: buildlink3.mk,v 1.6 2022/02/06 05:31:57 pho Exp $

BUILDLINK_TREE+=	ghc

.if !defined(GHC_BUILDLINK3_MK)
GHC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghc+=	ghc>=9.0
BUILDLINK_ABI_DEPENDS.ghc+=	ghc>=9.0.2nb1
BUILDLINK_PKGSRCDIR.ghc?=	../../lang/ghc90

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.endif	# GHC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghc
