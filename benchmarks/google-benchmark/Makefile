# $NetBSD: Makefile,v 1.4 2019/05/21 09:55:15 adam Exp $

DISTNAME=	benchmark-1.5
PKGNAME=	google-${DISTNAME}
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_PROJECT=	benchmark
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/google/benchmark
COMMENT=	Microbenchmark support library
LICENSE=	apache-2.0

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
CMAKE_ARGS+=	-DBENCHMARK_ENABLE_GTEST_TESTS=OFF
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
TEST_TARGET=	test

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
