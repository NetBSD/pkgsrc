# $NetBSD: Makefile,v 1.14 2017/08/01 14:59:00 wiz Exp $

DISTNAME=	mesa-demos-8.2.0
PKGNAME=	${DISTNAME:S/mesa-demos/glx-utils/}
PKGREVISION=	1
CATEGORIES=	x11 graphics
MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/demos/8.2.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cgit.freedesktop.org/mesa/demos/
COMMENT=	OpenGL glxgears and glxinfo
#LICENSE=	# Similar to mit but with SGI advertising clause.

NO_CONFIGURE=	yes
USE_LANGUAGES=	c

INSTALLATION_DIRS=	bin
LDFLAGS+=		-lX11	# ld 2.22 wants each library explicitly


do-build:
	cd ${WRKSRC}/src/xdemos && \
	${SETENV} ${MAKE_ENV} ${CC} -I../../include ${CFLAGS} \
		glxgears.c ${LDFLAGS} \
		-L../../lib -lGLU -lGL -lm -lXext \
		-o glxgears && \
	${SETENV} ${MAKE_ENV} ${CC} -I../../include ${CFLAGS} \
		glxinfo.c glinfo_common.c ${LDFLAGS} \
		-L../../lib -lGLU -lGL -lm -lXext -o glxinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xdemos/glxgears \
		${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/src/xdemos/glxinfo \
		${DESTDIR}${PREFIX}/bin/

.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
