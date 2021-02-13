# $NetBSD: Makefile,v 1.11 2021/02/13 08:01:00 mef Exp $

DISTNAME=	blaze-markup-0.8.2.3
CATEGORIES=	textproc

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Blazingly fast markup combinator library for Haskell
LICENSE=	modified-bsd


BUILDLINK_API_DEPENDS.ghc+=	ghc<9.0
.include "../../mk/haskell.mk"
.include "../../devel/hs-blaze-builder/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
