# $NetBSD: Makefile,v 1.88 2024/05/15 21:13:49 wiz Exp $

DISTNAME=	grpc-1.63.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=grpc/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://grpc.io/
COMMENT=	High performance, open-source universal RPC framework
LICENSE=	apache-2.0

USE_CXX_FEATURES=	c++14
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
FORCE_CXX_STD=		c++14

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON
# use cmake's find_package() to locate a pre-installed dependency
CMAKE_ARGS+=	-DgRPC_ABSL_PROVIDER=package
CMAKE_ARGS+=	-DgRPC_BENCHMARK_PROVIDER=package
CMAKE_ARGS+=	-DgRPC_CARES_PROVIDER=package
CMAKE_ARGS+=	-DgRPC_PROTOBUF_PROVIDER=package
CMAKE_ARGS+=	-DgRPC_RE2_PROVIDER=package
CMAKE_ARGS+=	-DgRPC_SSL_PROVIDER=package
CMAKE_ARGS+=	-DgRPC_ZLIB_PROVIDER=package

# This should be included in the distfile, but it's not,
# so CMakeFile.txt will try to download it.
CENSUS_VER=		0.3.0
CENSUS_DIST=		opencensus-proto-${CENSUS_VER}.tar.gz
SITES.${CENSUS_DIST}=	-${MASTER_SITE_GITHUB:=census-instrumentation/opencensus-proto/archive/}/v${CENSUS_VER}.tar.gz

DISTFILES=	${DEFAULT_DISTFILES} ${CENSUS_DIST}

PKGCONFIG_OVERRIDE=	cmake/pkg-config-template.pc.in

post-extract:
	${RMDIR} ${WRKSRC}/third_party/opencensus-proto
	${LN} -s ${WRKDIR}/opencensus-proto-* ${WRKSRC}/third_party/opencensus-proto

.include "../../benchmarks/google-benchmark/buildlink3.mk"
.include "../../devel/abseil/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/gflags/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/re2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libcares+=	libcares>=1.15.0nb1
.include "../../net/libcares/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
