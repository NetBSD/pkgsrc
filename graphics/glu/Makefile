# $NetBSD: Makefile,v 1.1.1.1 2000/10/15 11:45:21 rh Exp $
#

DISTNAME=		MesaLib-3.2.1
PKGNAME=		${DISTNAME:C/MesaLib/glu/}
CATEGORIES=		graphics
MASTER_SITES= 		ftp://ftp.mesa3d.org/mesa/ \
			http://download.sourceforge.net/mesa3d/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.ssec.wisc.edu/~brianp/Mesa.html

WRKSRC=			${WRKDIR}/${DISTNAME:C/Lib//}
USE_X11BASE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-static

do-build:
	cd ${WRKSRC}/src-glu && ${SETENV} ${MAKE_ENV} \
	${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET}

do-install:
	cd ${WRKSRC}/src-glu && ${SETENV} ${MAKE_ENV} \
	${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET}

post-install:
	${INSTALL_DATA_DIR} ${X11PREFIX}/include/GL
.for hdr in glu.h glu_mangle.h
	${INSTALL_DATA} ${WRKSRC}/include/GL/${hdr} ${X11PREFIX}/include/GL
.endfor

.include "../../mk/bsd.pkg.mk"
