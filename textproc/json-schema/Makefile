# $NetBSD: Makefile,v 1.14 2026/03/26 22:28:42 wiz Exp $

DISTNAME=	json-schema-1.4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=nfotex/}
GITHUB_RELEASE=	${DISTNAME}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	https://github.com/nfotex/json-schema/
COMMENT=	C++ library to validate JSON documents against JSON Schemata
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl:test pkg-config
TEST_TARGET=		test

USE_CXX_FEATURES=	c++17
FORCE_CXX_STD=		c++17

CMAKE_CONFIGURE_ARGS+=		-DBUILD_SHARED_LIBS=ON

.include "../../devel/cmake/build.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/jsoncpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
