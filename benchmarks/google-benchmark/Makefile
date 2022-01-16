# $NetBSD: Makefile,v 1.15 2022/01/16 23:09:35 wiz Exp $

DISTNAME=	benchmark-1.6.1
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

# as of 1.6.0
# 95% tests passed, 3 tests failed out of 61
# The following tests FAILED:
# 50 - reporter_output_test (Subprocess aborted)
# 52 - user_counters_test (Subprocess aborted)
# 57 - user_counters_tabular_test (Subprocess aborted)
TEST_TARGET=	test

BUILDLINK_TRANSFORM+=	rm:-Werror

PYTHON_FOR_BUILD_ONLY=	yes
REPLACE_PYTHON=		*.py */*.py */*/*.py

.include "../../lang/python/application.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
