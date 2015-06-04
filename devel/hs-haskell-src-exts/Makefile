# $NetBSD: Makefile,v 1.2 2015/06/04 20:08:59 szptvlfn Exp $

DISTNAME=	haskell-src-exts-1.16.0.1
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Manipulating Haskell source
LICENSE=	modified-bsd

BUILD_DEPENDS+=	happy>=1.17:../../devel/happy

.include "../../mk/haskell.mk"
.include "../../devel/hs-cpphs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
