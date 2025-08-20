# $NetBSD: Makefile,v 1.3 2025/08/20 11:34:50 wiz Exp $

DISTNAME=	cppcodec-0.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=tplgy/}
GITHUB_PROJECT=	cppcodec
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tplgy/cppcodec/
COMMENT=	C++11 library to encode/decode various codes
LICENSE=	mit

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

TEST_TARGET=	test

USE_CXX_FEATURES+=	c++14

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_CXX_STANDARD=14
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/catch2/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
