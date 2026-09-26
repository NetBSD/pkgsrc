# $NetBSD: Makefile,v 1.5 2026/09/26 14:25:07 wiz Exp $

DISTNAME=	cpuinfo-0.0.20260630
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=pytorch/}
GITHUB_TAG=	66ee79c038d70dad9f08705b2c9b3e58f6d8f512
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	benchmark-1.6.1.tar.gz
SITES.benchmark-1.6.1.tar.gz= \
	-${MASTER_SITE_GITHUB:=google/}benchmark/archive/v1.6.1.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytorch/cpuinfo/
COMMENT=	CPU information library
LICENSE=	2-clause-bsd

USE_LANGUAGES+=		c c++
USE_CXX_FEATURES+=	c++17
FORCE_CXX_STD=		c++17
USE_TOOLS+=		pkg-config
TEST_TARGET=		test

PKGCONFIG_OVERRIDE=	libcpuinfo.pc.in
CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_GOOGLETEST=ON
#CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DGOOGLEBENCHMARK_SOURCE_DIR=deps/googlebenchmark

post-extract:
	${MV} ${WRKDIR}/benchmark-1.6.1 ${WRKSRC}/deps/googlebenchmark

post-install:
.for file in \
	include/benchmark/benchmark.h \
	lib/cmake/benchmark/benchmarkConfig.cmake \
	lib/cmake/benchmark/benchmarkConfigVersion.cmake \
	lib/cmake/benchmark/benchmarkTargets-noconfig.cmake \
	lib/cmake/benchmark/benchmarkTargets.cmake \
	lib/libbenchmark.a \
	lib/libbenchmark_main.a \
	lib/pkgconfig/benchmark.pc
	${RM} -f ${DESTDIR}${PREFIX}/${file}
.endfor

.include "../../devel/cmake/build.mk"
# Can't use
#.include "../../benchmarks/google-benchmark/buildlink3.mk"
# because of
# https://github.com/pytorch/cpuinfo/issues/313
.include "../../devel/googletest/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
