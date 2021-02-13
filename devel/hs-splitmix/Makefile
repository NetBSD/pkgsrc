# $NetBSD: Makefile,v 1.2 2021/02/13 08:00:58 mef Exp $

DISTNAME=	splitmix-0.0.3
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Fast Splittable PRNG
LICENSE=	modified-bsd

BUILDLINK_API_DEPENDS.ghc+=	ghc<9.0
.include "../../mk/haskell.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
