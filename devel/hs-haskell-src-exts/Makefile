# $NetBSD: Makefile,v 1.6 2016/01/10 11:49:09 szptvlfn Exp $

DISTNAME=	haskell-src-exts-1.17.1
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Manipulating Haskell source
LICENSE=	modified-bsd

BUILD_DEPENDS+=	happy>=1.19:../../devel/happy

.include "../../mk/haskell.mk"
.include "../../devel/hs-cpphs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
