# $NetBSD: Makefile,v 1.3 2015/08/02 11:37:31 szptvlfn Exp $

DISTNAME=	haskell-src-exts-1.16.0.1
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Manipulating Haskell source
LICENSE=	modified-bsd

BUILD_DEPENDS+=	happy>=1.17:../../devel/happy

.include "../../mk/haskell.mk"
.include "../../devel/hs-cpphs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
