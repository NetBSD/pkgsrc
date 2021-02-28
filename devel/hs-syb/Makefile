# $NetBSD: Makefile,v 1.5 2021/02/28 13:59:45 mef Exp $

DISTNAME=	syb-0.7.1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Haskell "Scrap Your Boilerplate" Library
LICENSE=	modified-bsd

BUILDLINK_API_DEPENDS.ghc+=	ghc<=8.10
BUILDLINK_API_DEPENDS.ghc+=	ghc>=8.8
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
