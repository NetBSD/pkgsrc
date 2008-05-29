# $NetBSD: Makefile,v 1.6 2008/05/29 20:54:14 tnn Exp $

DISTNAME=	MesaDemos-${MESA_VERSION}
PKGNAME=	glx-utils-${MESA_VERSION}
CATEGORIES=	x11 graphics
COMMENT=	OpenGL glxgears and glxinfo

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../graphics/Mesa/Makefile.common"

MESA_PATCHFILES=	# don't track Mesa patchlevels

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
	${INSTALL_PROGRAM} ${WRKSRC}/progs/xdemos/glxgears \
		${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/progs/xdemos/glxinfo \
		${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
