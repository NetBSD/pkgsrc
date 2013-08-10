# $NetBSD: Makefile,v 1.11 2013/08/10 23:02:26 khorben Exp $

DISTNAME=	MesaDemos-${MESA_VERSION}
PKGNAME=	glx-utils-${MESA_VERSION}
CATEGORIES=	x11 graphics
COMMENT=	OpenGL glxgears and glxinfo

.include "../../graphics/Mesa/Makefile.common"
MESA_VERSION=	7.4.4

MESA_PATCHFILES=	# don't track Mesa patchlevels

INSTALLATION_DIRS=	bin
LDFLAGS+=		-lX11	# ld 2.22 wants each library explicitly

.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"

do-build:
	cd ${WRKSRC}/progs/xdemos && \
	${SETENV} ${MAKE_ENV} ${CC} -I../../include ${CFLAGS} \
		glxgears.c ${LDFLAGS} \
		-L../../lib -lGLU -lGL -lm -lXext \
		-o glxgears && \
	${SETENV} ${MAKE_ENV} ${CC} -I../../include ${CFLAGS} \
		glxinfo.c ${LDFLAGS} \
		-L../../lib -lGLU -lGL -lm -lXext -o glxinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/progs/xdemos/glxgears \
		${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/progs/xdemos/glxinfo \
		${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
