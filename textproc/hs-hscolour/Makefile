# $NetBSD: Makefile,v 1.4 2021/02/28 14:31:04 mef Exp $

DISTNAME=	hscolour-1.24.4
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Colourise Haskell code
LICENSE=	gnu-gpl-v2

BUILDLINK_API_DEPENDS.ghc+=	ghc<=8.10
BUILDLINK_API_DEPENDS.ghc+=	ghc>=8.8
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
