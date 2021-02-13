# $NetBSD: Makefile,v 1.2 2021/02/13 08:01:00 mef Exp $

DISTNAME=	haddock-library-1.8.0
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Library exposing some functionality of Haddock
LICENSE=	2-clause-bsd

BUILDLINK_API_DEPENDS.ghc+=	ghc<9.0
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
