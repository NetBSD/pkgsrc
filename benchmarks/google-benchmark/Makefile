# $NetBSD: Makefile,v 1.9 2020/10/07 20:49:56 wiz Exp $

DISTNAME=	benchmark-1.5.2
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
# as of 1.5.2
# 97% tests passed, 2 tests failed out of 59
# The following tests FAILED:
# 49 - reporter_output_test (Child aborted)
# 51 - user_counters_test (Child aborted)
TEST_TARGET=	test

BUILDLINK_TRANSFORM+=	rm:-Werror

PYTHON_FOR_BUILD_ONLY=	yes
REPLACE_PYTHON=		*.py */*.py */*/*.py

.include "../../lang/python/application.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
