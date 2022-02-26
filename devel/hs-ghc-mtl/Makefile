# $NetBSD: Makefile,v 1.8 2022/02/26 03:57:55 pho Exp $

DISTNAME=	ghc-mtl-1.2.1.0
PKGREVISION=	5
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Provides an mtl compatible version of the Ghc-Api monad transformers
LICENSE=	modified-bsd

# It appears it only supports GHC up to 8.8.x unfortunately.
BROKEN=		"${PKGNAME} is incompatible with GHC >= 9.0"

.include "../../mk/haskell.mk"
.include "../../devel/hs-extensible-exceptions/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
