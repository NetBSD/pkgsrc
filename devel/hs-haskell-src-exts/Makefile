# $NetBSD: Makefile,v 1.4 2015/11/18 21:31:14 szptvlfn Exp $

DISTNAME=	haskell-src-exts-1.17.0
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Manipulating Haskell source
LICENSE=	modified-bsd

BUILD_DEPENDS+=	happy>=1.17:../../devel/happy

.include "../../mk/haskell.mk"
.include "../../devel/hs-cpphs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
