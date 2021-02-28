# $NetBSD: Makefile,v 1.3 2021/02/28 13:59:45 mef Exp $

DISTNAME=	basement-0.0.11
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Foundation scrap box of array and string
LICENSE=	modified-bsd

BUILDLINK_API_DEPENDS.ghc+=	ghc<=8.10
BUILDLINK_API_DEPENDS.ghc+=	ghc>=8.8
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
