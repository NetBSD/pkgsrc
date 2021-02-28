# $NetBSD: Makefile,v 1.5 2021/02/28 01:47:36 mef Exp $

DISTNAME=	tagged-0.8.6.1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Haskell 98 phantom types to avoid unsafely passing dummy arguments
LICENSE=	modified-bsd

BUILDLINK_API_DEPENDS.ghc+=	ghc<9.0
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
