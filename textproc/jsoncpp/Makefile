# $NetBSD: Makefile,v 1.17 2023/01/24 18:36:34 wiz Exp $

DISTNAME=	jsoncpp-1.9.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=open-source-parsers/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/open-source-parsers/jsoncpp
COMMENT=	JSON reader and writer in C++
LICENSE=	public-domain OR mit

USE_LANGUAGES=		c c++
CMAKE_ARGS+=		-DBUILD_STATIC_LIBS=OFF
CMAKE_ARGS+=		-DBUILD_OBJECT_LIBS=OFF
CMAKE_ARGS+=		-DJSONCPP_WITH_TESTS=OFF
PKGCONFIG_OVERRIDE=	pkg-config/jsoncpp.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
