# $NetBSD: Makefile,v 1.1 2021/04/24 06:40:11 pho Exp $

DISTNAME=	prettyprinter-ansi-terminal-1.1.2
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	ANSI terminal backend for the "prettyprinter" package
LICENSE=	2-clause-bsd

# Haddock from lang/ghc90 on NetBSD/x86_64 fails to generate
# documentation for an unknown reason:
#
#   haddock: internal error: dist/doc/html/prettyprinter-ansi-terminal/haddock-respo
#   nse13373-1.txt: hGetContents: invalid argument (invalid byte sequence)
#
HASKELL_ENABLE_HADDOCK_DOCUMENTATION=	no

.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../textproc/hs-prettyprinter/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
