# $NetBSD: Makefile,v 1.58 2013/05/16 05:25:02 richard Exp $

PKGNAME=	glu-${MESA_PKGVERSION}
COMMENT=	GLU polygon tessellation facility for Mesa

CONFLICTS+=	Mesa-glx-[0-9]*
CONFLICTS+=	Mesa<3.2.1


PKGCONFIG_OVERRIDE+=    src/glu/glu.pc.in

CONFIGURE_ARGS+=        --enable-glu
CONFIGURE_ARGS+=        --disable-glut
CONFIGURE_ARGS+=        --disable-glw
CONFIGURE_ARGS+=        --with-dri-drivers=""

BUILD_DIRS=             src/glu
BUILD_TARGET=           default

INSTALL_DIRS=           src/glu
INSTALLATION_DIRS+=     include/GL

.include "../../graphics/Mesa/Makefile.lib"

BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=${MESA_VERSION}
.include "../../graphics/MesaLib/buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/GL/glu.h \
		${DESTDIR}${PREFIX}/include/GL/glu.h
	${INSTALL_DATA} ${WRKSRC}/include/GL/glu_mangle.h \
		${DESTDIR}${PREFIX}/include/GL/glu_mangle.h

.include "../../mk/bsd.pkg.mk"
