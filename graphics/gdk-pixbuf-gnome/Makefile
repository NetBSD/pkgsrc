# $NetBSD: Makefile,v 1.1.1.1 2000/11/29 17:23:53 wiz Exp $
#
.include "../gdk-pixbuf/Makefile.common"

PKGNAME=	${DISTNAME:S/-0/-gnome-0/}nb1

DEPENDS+=	gnome-libs>=1.0.53:../../x11/gnome-libs
DEPENDS+=	gdk-pixbuf>=0.9.0:../../graphics/gdk-pixbuf

do-install:
	${INSTALL_DATA} ${WRKSRC}/gdk-pixbuf/gnome-canvas-pixbuf.h \
		 ${PREFIX}/include/gdk-pixbuf
	${INSTALL_DATA} ${WRKSRC}/gnomecanvaspixbufConf.sh \
		 ${PREFIX}/lib
	cd ${WRKSRC}/gdk-pixbuf && \
		${SH} ../libtool  --mode=install ${INSTALL_DATA} \
			libgnomecanvaspixbuf.la ${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
