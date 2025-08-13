# $NetBSD: buildlink3.mk,v 1.5 2025/08/13 10:56:52 pho Exp $

BUILDLINK_TREE+=	ghc

.if !defined(GHC_BUILDLINK3_MK)
GHC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghc+=	ghc>=9.10.1nb4
BUILDLINK_ABI_DEPENDS.ghc+=	ghc>=9.10.1nb4
BUILDLINK_PKGSRCDIR.ghc?=	../../lang/ghc910

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.endif	# GHC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghc
