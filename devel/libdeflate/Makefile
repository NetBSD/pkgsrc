# $NetBSD: Makefile,v 1.3 2023/04/26 15:56:32 wiz Exp $

DISTNAME=	libdeflate-1.18
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ebiggers/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/ebiggers/libdeflate/
COMMENT=	Optimized deflate/zlib/gzip library
LICENSE=	mit

PKGCONFIG_OVERRIDE+=	libdeflate.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
