# $NetBSD: Makefile,v 1.18 2020/04/11 13:40:15 adam Exp $

DISTNAME=	msgpack-3.2.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=msgpack/}
GITHUB_PROJECT=	msgpack-c
GITHUB_RELEASE=	cpp-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://msgpack.org/
COMMENT=	Binary-based efficient object serialization library
LICENSE=	boost-license

USE_CMAKE=		yes
USE_LANGUAGES=		c c++11
PKGCONFIG_OVERRIDE=	msgpack.pc.in
TEST_ENV=		LD_LIBRARY_PATH=${WRKSRC}
TEST_TARGET=		test

CMAKE_ARGS+=	-DMSGPACK_CXX11=ON

.include "../../devel/googletest/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
