# $NetBSD: Makefile,v 1.16 2022/07/22 08:34:14 adam Exp $

DISTNAME=	benchmark-1.6.2
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

# as of 1.6.2
# 91% tests passed, 6 tests failed out of 67
# The following tests FAILED:
# 50 - reporter_output_test (Subprocess aborted)
# 52 - user_counters_test (Subprocess aborted)
# 57 - user_counters_tabular_test (Subprocess aborted)
# 65 - run_donotoptimize_assembly_test_CHECK (Failed)
# 66 - run_state_assembly_test_CHECK (Failed)
# 67 - run_clobber_memory_assembly_test_CHECK (Failed)
TEST_TARGET=	test

BUILDLINK_TRANSFORM+=	rm:-Werror

PYTHON_FOR_BUILD_ONLY=	yes
REPLACE_PYTHON=		*.py */*.py */*/*.py

.include "../../lang/python/application.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
