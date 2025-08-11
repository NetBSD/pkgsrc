# $NetBSD: Makefile,v 1.12 2025/08/11 08:50:14 wiz Exp $

DISTNAME=	json-schema-1.3
PKGREVISION=	3
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

CMAKE_CONFIGURE_ARGS+=		-DBUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/cmake/build.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/jsoncpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
