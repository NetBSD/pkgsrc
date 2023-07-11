# $NetBSD: Makefile,v 1.1 2023/07/11 23:46:57 charlotte Exp $

DISTNAME=	raylib-4.5.0
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

.include "../../devel/cmake/build.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glfw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
