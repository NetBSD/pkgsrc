# $NetBSD: Makefile,v 1.5 2001/03/18 04:33:55 mjl Exp $

.include "../gdk-pixbuf/Makefile.common"

PKGNAME=	${DISTNAME:S/gdk-pixbuf-/gdk-pixbuf-gnome-/}

COMMENT=	the GNOME image loading library GNOME canvas support add-on

DEPENDS+=	gnome-libs>=1.0.53:../../x11/gnome-libs
DEPENDS+=	gdk-pixbuf>=0.10.1:../../graphics/gdk-pixbuf

CONFLICTS+=	gdk-pixbuf<0.10.1

do-install:
	${INSTALL_DATA} ${WRKSRC}/gdk-pixbuf/gnome-canvas-pixbuf.h \
	  ${PREFIX}/include/gdk-pixbuf
	${INSTALL_DATA} ${WRKSRC}/gnomecanvaspixbufConf.sh \
	  ${PREFIX}/lib
	cd ${WRKSRC}/gdk-pixbuf && \
	${SH} ../libtool --mode=install ${INSTALL_DATA} \
	  libgnomecanvaspixbuf.la ${PREFIX}/lib
	cd ${WRKSRC}/doc && \
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} \
	  ${INSTALL_TARGET}

.include "../../mk/bsd.pkg.mk"
