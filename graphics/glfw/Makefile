# $NetBSD: Makefile,v 1.13 2023/01/24 18:36:26 wiz Exp $

DISTNAME=	glfw-3.3.8
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=glfw/}

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	https://www.glfw.org/
COMMENT=	Free, portable framework for OpenGL application development
LICENSE=	zlib

USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_ARGS+=	-DGLFW_BUILD_DOCS=OFF
CMAKE_ARGS+=	-DGLFW_BUILD_EXAMPLES=OFF

PKGCONFIG_OVERRIDE+=	src/glfw3.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Darwin"
.  include "options.mk"
.  include "../../graphics/MesaLib/buildlink3.mk"
.  include "../../graphics/glu/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
