# $NetBSD: Makefile,v 1.2 2016/02/28 19:44:56 joerg Exp $
#

DISTNAME=	glfw-3.1.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=glfw/}

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://www.glfw.org/
COMMENT=	GLFW is a free, Open Source, multi-platform library of OpenGL
LICENSE=	zlib

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_ARGS+=	-DGLFW_BUILD_DOCS=OFF

# Problem reported and fixed (differently) upstream:
#  https://github.com/glfw/glfw/issues/646
# It will not be needed for the next release.
SUBST_CLASSES+=		soname
SUBST_STAGE.soname=	pre-configure
SUBST_MESSAGE.soname=	Avoid hardcoded libGL.so
SUBST_FILES.soname=	src/glx_context.c
SUBST_SED.soname=	-e '/soname/ s/libGL\.so\.1/libGL.so/'

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
