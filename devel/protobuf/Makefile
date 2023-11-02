# $NetBSD: Makefile,v 1.68 2023/11/02 12:17:25 wiz Exp $
#
# When updating this, please also update devel/py-protobuf
#
# Please note: this package often changes the major version
# number of libraries, so please compare binary packages
# from before and after, and do a recursive PKGREVISION
# bump if necessary

DISTNAME=	protobuf-24.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=protocolbuffers/}
GITHUB_PROJECT=	protobuf
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/protocolbuffers/protobuf
COMMENT=	Google protocol buffers
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++14

CMAKE_ARGS+=		-Dprotobuf_ABSL_PROVIDER=package
CMAKE_ARGS+=		-Dprotobuf_BUILD_SHARED_LIBS=ON
# requires googletest to be checked out in third_party/googletest
CMAKE_ARGS+=		-Dprotobuf_BUILD_TESTS=OFF

# the [[ command will skip a test that would otherwise run
CHECK_PORTABILITY_SKIP+=	src/google/protobuf/compiler/zip_output_unittest.sh

.include "../../devel/cmake/build.mk"
#.include "../../devel/googletest/buildlink3.mk"
BUILDLINK_API_DEPENDS.abseil+=	abseil>=20230125.3
.include "../../devel/abseil/buildlink3.mk"
BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.0.4
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
