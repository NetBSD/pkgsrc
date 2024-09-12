# $NetBSD: Makefile,v 1.19 2024/09/12 06:42:32 adam Exp $

DISTNAME=	jsoncpp-1.9.6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=open-source-parsers/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/open-source-parsers/jsoncpp
COMMENT=	JSON reader and writer in C++
LICENSE=	public-domain OR mit

USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE=	pkg-config/jsoncpp.pc.in

CMAKE_CONFIGURE_ARGS+=		-DBUILD_STATIC_LIBS=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_OBJECT_LIBS=OFF
CMAKE_CONFIGURE_ARGS+=		-DJSONCPP_WITH_TESTS=OFF

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
