# $NetBSD: Makefile,v 1.30 2006/09/09 02:42:01 obache Exp $

.include "../../graphics/gdk-pixbuf/Makefile.common"

PKGNAME=	${DISTNAME:S/gdk-pixbuf-/gdk-pixbuf-gnome-/}
PKGREVISION=	6
COMMENT=	The GNOME image loading library GNOME canvas support add-on

CONFLICTS+=	gdk-pixbuf<0.10.1

# Don't enable the next line or we'll conflict with gtk2!
#CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

CONFIGURE_ARGS+=	--enable-gtk-doc=no

INSTALLATION_DIRS=	include/gdk-pixbuf-1.0/gdk-pixbuf lib

.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

do-install:
	${INSTALL_DATA} ${WRKSRC}/gdk-pixbuf/gnome-canvas-pixbuf.h \
	  ${PREFIX}/include/gdk-pixbuf-1.0/gdk-pixbuf
	${INSTALL_DATA} ${WRKSRC}/gnomecanvaspixbufConf.sh \
	  ${PREFIX}/lib
	cd ${WRKSRC}/gdk-pixbuf && \
	${SH} ../libtool --mode=install ${INSTALL_DATA} \
	  libgnomecanvaspixbuf.la ${PREFIX}/lib
	cd ${WRKSRC}/doc && \
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKE_FILE} \
	  ${INSTALL_TARGET}

.include "../../mk/bsd.pkg.mk"
