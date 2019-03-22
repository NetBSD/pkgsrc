# $NetBSD: Makefile,v 1.7 2019/03/22 08:25:51 adam Exp $

DISTNAME=	grpc-1.19.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=grpc/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://grpc.io/
COMMENT=	High performance, open-source universal RPC framework
LICENSE=	apache-2.0

USE_CMAKE=	yes
USE_LANGUAGES+=	c c++11
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=on
CMAKE_ARGS+=	-DgRPC_BENCHMARK_PROVIDER=package
CMAKE_ARGS+=	-DgRPC_CARES_PROVIDER=package
CMAKE_ARGS+=	-DgRPC_GFLAGS_PROVIDER=package
CMAKE_ARGS+=	-DgRPC_PROTOBUF_PROVIDER=package
CMAKE_ARGS+=	-DgRPC_SSL_PROVIDER=package
CMAKE_ARGS+=	-DgRPC_ZLIB_PROVIDER=package

.include "../../benchmarks/google-benchmark/buildlink3.mk"
.include "../../devel/gflags/buildlink3.mk"
BUILDLINK_API_DEPENDS.protobuf+=	protobuf>=3.5
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
