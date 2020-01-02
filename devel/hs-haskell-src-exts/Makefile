# $NetBSD: Makefile,v 1.7 2020/01/02 04:52:43 pho Exp $

DISTNAME=	haskell-src-exts-1.22.0
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Manipulating Haskell source
LICENSE=	modified-bsd

BUILD_DEPENDS+=	happy>=1.19:../../devel/happy

.include "../../mk/haskell.mk"
.include "../../devel/hs-fail/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
