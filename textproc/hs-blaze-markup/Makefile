# $NetBSD: Makefile,v 1.12 2021/02/18 15:07:28 mef Exp $

DISTNAME=	blaze-markup-0.8.2.3
CATEGORIES=	textproc

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Blazingly fast markup combinator library for Haskell
LICENSE=	modified-bsd


BUILDLINK_API_DEPENDS.ghc+=	ghc<8.10
.include "../../mk/haskell.mk"
.include "../../devel/hs-blaze-builder/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
