# $NetBSD: Makefile,v 1.3 2021/02/18 15:07:26 mef Exp $

DISTNAME=	haddock-library-1.8.0
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Library exposing some functionality of Haddock
LICENSE=	2-clause-bsd

BUILDLINK_API_DEPENDS.ghc+=	ghc<8.10
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
