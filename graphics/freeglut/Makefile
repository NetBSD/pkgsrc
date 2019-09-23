# $NetBSD: Makefile,v 1.23 2019/09/23 12:28:49 nia Exp $

DISTNAME=	freeglut-3.0.0
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freeglut/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://freeglut.sourceforge.net/
COMMENT=	Alternative to the OpenGL Utility Toolkit (GLUT) library
LICENSE=	x11

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release

PKGCONFIG_OVERRIDE=	freeglut.pc.in

# Install glut.pc for compatibility.
post-install:
	${INSTALL_DATA} ${DESTDIR}${PREFIX}/lib/pkgconfig/freeglut.pc \
	    ${DESTDIR}${PREFIX}/lib/pkgconfig/glut.pc

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
