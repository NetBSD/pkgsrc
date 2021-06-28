# $NetBSD: Makefile,v 1.16 2021/06/28 18:46:09 wiz Exp $

DISTNAME=	snappy-1.1.9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://google.github.io/snappy/
COMMENT=	General purpose data compression library
LICENSE=	apache-2.0

USE_CMAKE=		yes
USE_LANGUAGES=		c c++

CMAKE_ARGS+=		-DSNAPPY_BUILD_TESTS:BOOL=OFF
CMAKE_ARGS+=		-DSNAPPY_BUILD_BENCHMARKS:BOOL=OFF
CMAKE_ARGS+=		-DBUILD_SHARED_LIBS=ON

.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
