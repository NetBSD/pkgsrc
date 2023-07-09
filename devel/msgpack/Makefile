# $NetBSD: Makefile,v 1.20 2023/07/09 14:45:20 nia Exp $

DISTNAME=	msgpack-3.3.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=msgpack/}
GITHUB_PROJECT=	msgpack-c
GITHUB_RELEASE=	cpp-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://msgpack.org/
COMMENT=	Binary-based efficient object serialization library
LICENSE=	boost-license

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE=	msgpack.pc.in
TEST_ENV=		LD_LIBRARY_PATH=${WRKSRC}
TEST_TARGET=		test

# Note that msgpack currently needs to be built with MSGPACK_CXX17 when
# googletest is used due to it requiring minimum C++14 in its headers.
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_GTest=ON
CMAKE_ARGS+=	-DMSGPACK_BUILD_TESTS=OFF
CMAKE_ARGS+=	-DMSGPACK_CXX11=ON
GCC_REQD+=	4.8

#.include "../../devel/googletest/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
