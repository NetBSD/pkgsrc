# $NetBSD: Makefile,v 1.77 2024/05/29 16:02:15 adam Exp $
#
# When updating this, please also update devel/py-protobuf.
#
# NB: This package has very strange library versioning, lacking the
# usual libfoo.so.X symlink to libfoo.so.X.Y.  Thus, any change to the
# so version, e.g. .25.2.0 to .25.3.0, is an ABI change.  It is highly
# likely that any upstream release, even if apparently minor, will
# require a recursive revbump.

DISTNAME=	protobuf-27.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=protocolbuffers/}
GITHUB_PROJECT=	protobuf
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/protocolbuffers/protobuf
COMMENT=	Google protocol buffers
LICENSE=	modified-bsd

USE_CXX_FEATURES=	c++14
USE_LANGUAGES=		c c++

# Fails with C++14 default language
FORCE_CXX_STD=		c++14

CMAKE_ARGS+=	-Dprotobuf_ABSL_PROVIDER=package
CMAKE_ARGS+=	-Dprotobuf_BUILD_SHARED_LIBS=ON
# requires googletest to be checked out in third_party/googletest
CMAKE_ARGS+=	-Dprotobuf_BUILD_TESTS=OFF

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
