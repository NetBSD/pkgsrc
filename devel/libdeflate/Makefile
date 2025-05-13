# $NetBSD: Makefile,v 1.10 2025/05/13 05:51:50 adam Exp $

DISTNAME=	libdeflate-1.24
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ebiggers/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/ebiggers/libdeflate
COMMENT=	Optimized deflate/zlib/gzip library
LICENSE=	mit

PKGCONFIG_OVERRIDE+=	libdeflate.pc.in
USE_CC_FEATURES=	c11

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
