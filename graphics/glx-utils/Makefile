# $NetBSD: Makefile,v 1.2 2006/08/01 21:40:20 jlam Exp $

DISTNAME=	MesaDemos-${MESA_VERSION}
PKGNAME=	glx-utils-${MESA_VERSION}
CATEGORIES=	x11 graphics
COMMENT=	OpenGL glxgears and glxinfo

.include "../../graphics/Mesa/Makefile.common"

INSTALLATION_DIRS=	bin

.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"

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

.include "../../mk/bsd.pkg.mk"
