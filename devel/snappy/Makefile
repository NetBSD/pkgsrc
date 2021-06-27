# $NetBSD: Makefile,v 1.15 2021/06/27 11:45:54 tnn Exp $

GITHUB_TAG=	${PKGVERSION_NOREV}
DISTNAME=	snappy-1.1.8
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://google.github.io/snappy/
COMMENT=	General purpose data compression library
LICENSE=	apache-2.0


USE_CMAKE=		yes
USE_LANGUAGES=		c c++
TEST_TARGET=		test
TEST_ENV+=		LD_LIBRARY_PATH=${WRKSRC}

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
CMAKE_ARGS+=	-DSNAPPY_BUILD_TESTS=ON
.include "../../devel/googletest/buildlink3.mk"
.else
CMAKE_ARGS+=	-DSNAPPY_BUILD_TESTS=OFF
.endif

.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
