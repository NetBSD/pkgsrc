# $NetBSD: Makefile,v 1.19 2024/03/22 07:53:25 wiz Exp $

DISTNAME=	snappy-1.1.10
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://google.github.io/snappy/
COMMENT=	General purpose data compression library
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DSNAPPY_BUILD_TESTS=OFF
CMAKE_ARGS+=	-DSNAPPY_BUILD_BENCHMARKS=OFF
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
