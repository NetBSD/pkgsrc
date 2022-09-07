# $NetBSD: Makefile,v 1.1 2022/09/07 02:56:00 pho Exp $

DISTNAME=	newtype-0.2.2.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Typeclass and set of functions for working with newtypes
LICENSE=	modified-bsd

# Relax version constraints
SUBST_CLASSES+=		cabal
SUBST_STAGE.cabal=	post-extract
SUBST_FILES.cabal=	newtype.cabal
SUBST_SED.cabal=	-e 's/base >= 4.5 && < 4.14/base/'

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
