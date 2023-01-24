# $NetBSD: Makefile,v 1.10 2023/01/24 18:36:34 wiz Exp $

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
CMAKE_ARGS+=		-DBUILD_SHARED_LIBS=ON
TEST_TARGET=		test

.include "../../devel/cmake/build.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/jsoncpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
