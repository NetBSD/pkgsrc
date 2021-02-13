# $NetBSD: Makefile,v 1.2 2021/02/13 08:00:59 mef Exp $

DISTNAME=	unliftio-core-0.1.2.0
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	The MonadUnliftIO typeclass for unlifting monads to IO
LICENSE=	mit

BUILDLINK_API_DEPENDS.ghc+=	ghc<9.0
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
