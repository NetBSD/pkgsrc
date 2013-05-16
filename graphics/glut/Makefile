# $NetBSD: Makefile,v 1.54 2013/05/16 05:28:13 richard Exp $

PKGNAME=	glut-${MESA_PKGVERSION}
COMMENT=	GLUT Graphics library similar to SGI's OpenGL

CONFLICTS+=	Mesa-glx-[0-9]*
CONFLICTS+=	Mesa<3.2.1


PKGCONFIG_OVERRIDE+=    src/glut/glx/glut.pc.in

.include "../../graphics/Mesa/Makefile.lib"

BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=${MESA_PKGVERSION}
BUILDLINK_API_DEPENDS.glu+=	glu>=${MESA_PKGVERSION}

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"

CONFIGURE_ARGS+=        --enable-glu
CONFIGURE_ARGS+=        --enable-glut
CONFIGURE_ARGS+=        --disable-glw
CONFIGURE_ARGS+=        --with-dri-drivers=""

BUILD_DIRS=             src/glut/glx
BUILD_TARGET=           default

INSTALL_DIRS=           src/glut/glx
INSTALLATION_DIRS+=     include/GL

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/GL/glut.h \
		${DESTDIR}${PREFIX}/include/GL/glut.h
	${INSTALL_DATA} ${WRKSRC}/include/GL/glutf90.h \
		${DESTDIR}${PREFIX}/include/GL/glutf90.h

.include "../../mk/bsd.pkg.mk"
