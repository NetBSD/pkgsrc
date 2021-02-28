# $NetBSD: Makefile,v 1.7 2021/02/28 13:59:45 mef Exp $

DISTNAME=	tagged-0.8.6.1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Haskell 98 phantom types to avoid unsafely passing dummy arguments
LICENSE=	modified-bsd

BUILDLINK_API_DEPENDS.ghc+=	ghc<=8.10
BUILDLINK_API_DEPENDS.ghc+=	ghc>=8.8
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
