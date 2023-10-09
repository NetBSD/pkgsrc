# $NetBSD: buildlink3.mk,v 1.4 2023/10/09 02:49:52 pho Exp $

BUILDLINK_TREE+=	ghc

.if !defined(GHC_BUILDLINK3_MK)
GHC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghc+=	ghc>=9.4.7
BUILDLINK_ABI_DEPENDS.ghc+=	ghc>=9.4.7
BUILDLINK_PKGSRCDIR.ghc?=	../../lang/ghc94

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.endif	# GHC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghc
