# $NetBSD: Makefile,v 1.3 2021/02/18 15:07:27 mef Exp $

DISTNAME=	unliftio-core-0.1.2.0
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	The MonadUnliftIO typeclass for unlifting monads to IO
LICENSE=	mit

BUILDLINK_API_DEPENDS.ghc+=	ghc<8.10
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
