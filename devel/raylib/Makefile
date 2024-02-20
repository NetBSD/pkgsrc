# $NetBSD: Makefile,v 1.3 2024/02/20 22:00:35 charlotte Exp $

DISTNAME=	raylib-5.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=raysan5/}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://www.raylib.com/
COMMENT=	Simple library to enjoy videogames programming
LICENSE=	zlib

USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DPLATFORM=Desktop
CMAKE_ARGS+=	-DUSE_EXTERNAL_GLFW:BOOL=ON
CMAKE_ARGS+=	-DBUILD_EXAMPLES:BOOL=OFF
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON

.include "../../devel/cmake/build.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glfw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
