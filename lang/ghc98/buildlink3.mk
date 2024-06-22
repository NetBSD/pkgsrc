# $NetBSD: buildlink3.mk,v 1.3 2024/06/22 12:16:40 jperkin Exp $

BUILDLINK_TREE+=	ghc

.if !defined(GHC_BUILDLINK3_MK)
GHC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghc+=	ghc>=9.8.2
BUILDLINK_ABI_DEPENDS.ghc+=	ghc>=9.8.2nb1
BUILDLINK_PKGSRCDIR.ghc?=	../../lang/ghc98

.include "../../mk/bsd.fast.prefs.mk"

# A regrettable hack.  See Makefile for background.
.if ${OPSYS} != "Darwin"
.include "../../converters/libiconv/buildlink3.mk"
.endif

.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.endif	# GHC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghc
