# $NetBSD: buildlink3.mk,v 1.1 2023/01/21 04:49:25 pho Exp $

BUILDLINK_TREE+=	ghc

.if !defined(GHC_BUILDLINK3_MK)
GHC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghc+=	ghc>=9.4.4
BUILDLINK_ABI_DEPENDS.ghc+=	ghc>=9.4.4
BUILDLINK_PKGSRCDIR.ghc?=	../../lang/ghc94

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.endif	# GHC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghc
