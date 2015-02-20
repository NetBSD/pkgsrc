# $NetBSD: buildlink3.mk,v 1.7 2015/02/20 19:10:29 pho Exp $

BUILDLINK_TREE+=	ghc

.if !defined(GHC_BUILDLINK3_MK)
GHC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghc+=	ghc>=7.6.3
BUILDLINK_ABI_DEPENDS.ghc+=	ghc>=7.6.3nb6
BUILDLINK_PKGSRCDIR.ghc?=	../../lang/ghc7

# On FreeBSD we need pkgsrc libiconv. See bootstrap.mk for details.
.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "FreeBSD"
USE_BUILTIN.iconv=	no
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.endif	# GHC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghc
