# $NetBSD: Makefile,v 1.19 2002/11/28 18:48:16 drochner Exp $

.include "../gdk-pixbuf/Makefile.common"

PKGNAME=	${DISTNAME:S/gdk-pixbuf-/gdk-pixbuf-gnome-/}
COMMENT=	the GNOME image loading library GNOME canvas support add-on

CONFLICTS+=	gdk-pixbuf<0.10.1

BUILDLINK_DEPENDS.gdk-pixbuf=	gdk-pixbuf>=0.11.0nb1

USE_X11=	# defined
# gtk-doc wants an X11 DISPLAY during build, so disable it
CONFIGURE_ENV+=	GTKDOC=false

do-install:
	${INSTALL_DATA} ${WRKSRC}/gdk-pixbuf/gnome-canvas-pixbuf.h \
	  ${PREFIX}/include/gdk-pixbuf-1.0/gdk-pixbuf
	${INSTALL_DATA} ${WRKSRC}/gnomecanvaspixbufConf.sh \
	  ${PREFIX}/lib
	cd ${WRKSRC}/gdk-pixbuf && \
	${SH} ../libtool --mode=install ${INSTALL_DATA} \
	  libgnomecanvaspixbuf.la ${PREFIX}/lib
	cd ${WRKSRC}/doc && \
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} \
	  ${INSTALL_TARGET}

.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
