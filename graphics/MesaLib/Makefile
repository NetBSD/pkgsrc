# $NetBSD: Makefile,v 1.1.1.1 2000/10/15 11:41:17 rh Exp $
#

DISTNAME=		MesaLib-3.2.1
WRKSRC=			${WRKDIR}/${DISTNAME:S/Lib//}
CATEGORIES=		graphics
MASTER_SITES= 		ftp://ftp.mesa3d.org/mesa/ \
			http://download.sourceforge.net/mesa3d/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.ssec.wisc.edu/~brianp/Mesa.html

CHECK_MESA=		yes
USE_X11BASE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-static

.include "../../mk/bsd.prefs.mk"

.if ${HAVE_BUILTIN_MESA} != "NO"
IGNORE=			"MesaLib/GLX has already been installed as part of XFree-4.x"
.endif

do-build:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} \
	${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET}

do-install:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} \
	${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET}

post-install:
	${INSTALL_DATA_DIR} ${X11PREFIX}/include/GL
.for hdr in gl.h gl_mangle.h glx.h glx_mangle.h osmesa.h \
		xmesa.h xmesa_x.h xmesa_xf86.h
	${INSTALL_DATA} ${WRKSRC}/include/GL/${hdr} ${X11PREFIX}/include/GL
.endfor

.include "../../mk/bsd.pkg.mk"
