# $NetBSD: Makefile,v 1.3 2017/12/04 18:20:30 minskim Exp $

DISTNAME=	grpc-1.7.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=grpc/}
GITHUB_PROJECT=	grpc
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://grpc.io/
COMMENT=	High performance, open-source universal RPC framework
LICENSE=	apache-2.0

USE_CMAKE=	yes
USE_LANGUAGES+=	c c++

CMAKE_ARGS+=	-DgRPC_BENCHMARK_PROVIDER=package
CMAKE_ARGS+=	-DgRPC_CARES_PROVIDER=package
CMAKE_ARGS+=	-DgRPC_GFLAGS_PROVIDER=package
CMAKE_ARGS+=	-DgRPC_PROTOBUF_PROVIDER=package
CMAKE_ARGS+=	-DgRPC_SSL_PROVIDER=package
CMAKE_ARGS+=	-DgRPC_ZLIB_PROVIDER=package

SUBST_CLASSES+=			fix-include
SUBST_STAGE.fix-include=	pre-configure
SUBST_MESSAGE.fix-include=	Fixing include paths.
SUBST_FILES.fix-include=	CMakeLists.txt
SUBST_SED.fix-include=		-e 's, /usr/local/, ${PREFIX}/,g'

.include "../../benchmarks/google-benchmark/buildlink3.mk"
.include "../../devel/gflags/buildlink3.mk"
BUILDLINK_API_DEPENDS.protobuf+=	protobuf>=3.4
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
