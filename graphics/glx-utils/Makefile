# $NetBSD: Makefile,v 1.1.1.1 2006/06/13 23:44:09 reed Exp $

PKGNAME=	glx-utils-${MESA_VERSION}
CATEGORIES=	x11 graphics
COMMENT=	OpenGL glxgears and glxinfo

PATCHDIR=		${.CURDIR}/patches
DISTINFO_FILE=		${.CURDIR}/distinfo

.include "../../graphics/Mesa/Makefile.common"
DISTNAME=	MesaDemos-${MESA_VERSION}
WRKSRC=		${WRKDIR}/Mesa-${MESA_VERSION}

USE_LANGUAGES=		c c++
INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC}/progs/xdemos && \
	${SETENV} ${MAKE_ENV} ${CC} -I../../include ${CFLAGS} \
		${PTHREAD_CFLAGS} glxgears.c ${LDFLAGS} ${PTHREAD_LDFLAGS} \
		-L../../lib -lGLU -lGL -lm -lXext ${PTHREAD_LIBS} \
		-o glxgears && \
	${SETENV} ${MAKE_ENV} ${CC} -I../../include ${CFLAGS} \
		${PTHREAD_CFLAGS} glxinfo.c ${LDFLAGS} ${PTHREAD_LDFLAGS} \
		-L../../lib -lGLU -lGL -lm -lXext ${PTHREAD_LIBS} -o glxinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/progs/xdemos/glxgears ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/progs/xdemos/glxinfo ${PREFIX}/bin/

.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
