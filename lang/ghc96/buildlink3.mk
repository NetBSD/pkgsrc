# $NetBSD: buildlink3.mk,v 1.3 2023/10/24 06:38:45 pho Exp $

BUILDLINK_TREE+=	ghc

.if !defined(GHC_BUILDLINK3_MK)
GHC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghc+=	ghc>=9.6.3nb2
BUILDLINK_ABI_DEPENDS.ghc+=	ghc>=9.6.3nb2
BUILDLINK_PKGSRCDIR.ghc?=	../../lang/ghc96

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.endif	# GHC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghc
