# $NetBSD: Makefile,v 1.4 2019/07/08 10:36:26 nia Exp $
#

DISTNAME=	glfw-3.2.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=glfw/}

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	https://www.glfw.org/
COMMENT=	GLFW is a free, Open Source, multi-platform library of OpenGL
LICENSE=	zlib

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_ARGS+=	-DGLFW_BUILD_DOCS=OFF

.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
