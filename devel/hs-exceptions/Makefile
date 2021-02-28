# $NetBSD: Makefile,v 1.8 2021/02/28 13:59:45 mef Exp $

DISTNAME=	exceptions-0.10.4
CATEGORIES=	devel

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Extensible optionally-pure exceptions
LICENSE=	modified-bsd

BUILDLINK_API_DEPENDS.ghc+=	ghc<=8.10
BUILDLINK_API_DEPENDS.ghc+=	ghc>=8.8
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
