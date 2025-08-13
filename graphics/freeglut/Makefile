# $NetBSD: Makefile,v 1.38 2025/08/13 06:05:51 wiz Exp $

DISTNAME=	freeglut-3.6.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freeglut/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://freeglut.sourceforge.net/
COMMENT=	Alternative to the OpenGL Utility Toolkit (GLUT) library
LICENSE=	x11

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_CONFIGURE_ARGS+=	-DFREEGLUT_BUILD_DEMOS=OFF
CMAKE_CONFIGURE_ARGS+=	-DFREEGLUT_REPLACE_GLUT=ON

PKGCONFIG_OVERRIDE=	freeglut.pc.in

# Install freeglut.pc for compatibility.
post-install:
	${INSTALL_DATA} ${DESTDIR}${PREFIX}/lib/pkgconfig/glut.pc \
	    ${DESTDIR}${PREFIX}/lib/pkgconfig/freeglut.pc

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
