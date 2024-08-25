# $NetBSD: Makefile,v 1.4 2024/08/25 06:18:37 wiz Exp $

DISTNAME=	raylib-5.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=raysan5/}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://www.raylib.com/
COMMENT=	Simple library to enjoy videogames programming
LICENSE=	zlib

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DPLATFORM=Desktop
CMAKE_CONFIGURE_ARGS+=	-DUSE_EXTERNAL_GLFW:BOOL=ON
CMAKE_CONFIGURE_ARGS+=	-DBUILD_EXAMPLES:BOOL=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON

.include "../../devel/cmake/build.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glfw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
