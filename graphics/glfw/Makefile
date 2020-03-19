# $NetBSD: Makefile,v 1.7 2020/03/19 11:23:53 nia Exp $

DISTNAME=	glfw-3.3.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=glfw/}

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	https://www.glfw.org/
COMMENT=	Free, portable framework for OpenGL application development
LICENSE=	zlib

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_ARGS+=	-DGLFW_BUILD_DOCS=OFF
CMAKE_ARGS+=	-DGLFW_BUILD_EXAMPLES=OFF

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} != "Darwin"
.  include "options.mk"
.  include "../../graphics/MesaLib/buildlink3.mk"
.  include "../../graphics/glu/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
