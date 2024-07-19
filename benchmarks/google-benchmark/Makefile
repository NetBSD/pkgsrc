# $NetBSD: Makefile,v 1.26 2024/07/19 06:49:06 adam Exp $

DISTNAME=	benchmark-1.8.5
PKGNAME=	google-${DISTNAME}
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_PROJECT=	benchmark
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/google/benchmark
COMMENT=	Microbenchmark support library
LICENSE=	apache-2.0

USE_CXX_FEATURES=	c++14
USE_LANGUAGES=		c c++
TEST_TARGET=		test

CMAKE_ARGS+=	-DBENCHMARK_ENABLE_GTEST_TESTS=OFF
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release

BUILDLINK_TRANSFORM+=	rm:-Werror

PYTHON_FOR_BUILD_ONLY=	yes
REPLACE_PYTHON=		*.py */*.py */*/*.py

.include "../../devel/cmake/build.mk"
.include "../../lang/python/application.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
