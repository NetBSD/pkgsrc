# $NetBSD: Makefile,v 1.3 2021/02/18 15:07:28 mef Exp $

DISTNAME=	splitmix-0.0.3
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Fast Splittable PRNG
LICENSE=	modified-bsd

BUILDLINK_API_DEPENDS.ghc+=	ghc<8.10
.include "../../mk/haskell.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
