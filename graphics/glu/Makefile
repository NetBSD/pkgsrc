# $NetBSD: Makefile,v 1.10 2001/09/27 23:18:11 jlam Exp $
#

.include "../Mesa/Makefile.common"

DISTNAME=		MesaLib-${MESA_VERSION}
PKGNAME=		${DISTNAME:C/MesaLib/glu/}
CATEGORIES=		graphics
MASTER_SITES= 		${MASTER_SITE_SOURCEFORGE:=mesa3d/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.mesa3d.org/
COMMENT=		GLU polygon tesselation facility for Mesa

CONFLICTS+=		Mesa-glx-[0-9]*
CONFLICTS+=		Mesa<3.2.1

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
