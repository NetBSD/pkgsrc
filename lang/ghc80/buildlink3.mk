# $NetBSD: buildlink3.mk,v 1.1 2020/01/03 15:24:08 pho Exp $

BUILDLINK_TREE+=	ghc

.if !defined(GHC_BUILDLINK3_MK)
GHC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghc+=	ghc>=8.0.2
BUILDLINK_ABI_DEPENDS.ghc+=	ghc>=8.0.2
BUILDLINK_PKGSRCDIR.ghc?=	../../lang/ghc80

# On FreeBSD we need pkgsrc libiconv. See bootstrap.mk for details.
.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "FreeBSD"
USE_BUILTIN.iconv=	no
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.endif	# GHC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghc
