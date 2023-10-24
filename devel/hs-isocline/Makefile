# $NetBSD: Makefile,v 1.1 2023/10/24 14:08:06 pho Exp $

DISTNAME=	isocline-1.0.9
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Portable alternative to GNU Readline
LICENSE=	mit

# Do not build or install the example executable. We don't want it in
# pkgsrc.
SUBST_CLASSES+=		cabal
SUBST_STAGE.cabal=	post-extract
SUBST_FILES.cabal=	isocline.cabal
SUBST_SED.cabal=	-e '/^executable /a\${.newline}  buildable: false'

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
