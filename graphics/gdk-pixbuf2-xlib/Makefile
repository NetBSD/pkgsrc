# $NetBSD: Makefile,v 1.24 2019/10/04 23:37:20 ryoon Exp $

DISTNAME=	gdk-pixbuf-${PIXBUF2_VERSION}
PKGNAME=	gdk-pixbuf2-xlib-${PIXBUF2_VERSION}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gdk-pixbuf/${MSITE_VERSION}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.gnome.org/gdk-pixbuf
COMMENT=	Image loaders for gtk2 (X11 support)
LICENSE=	gnu-gpl-v2

PATCHDIR=	${.CURDIR}/../../graphics/gdk-pixbuf2/patches
DISTINFO_FILE=	${.CURDIR}/../../graphics/gdk-pixbuf2/distinfo

CONFLICTS+=	gtk2+<2.22

.include "../../graphics/gdk-pixbuf2/Makefile.version"

USE_TOOLS+=	gmake pkg-config
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/gdk-pixbuf

MESON_ARGS+=	-D installed_tests=false
MESON_ARGS+=	-D x11=true
PKGCONFIG_OVERRIDE_STAGE=pre-install
PKGCONFIG_OVERRIDE=    output/meson-private/gdk-pixbuf-xlib-2.0.pc

post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/*
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/gdk-pixbuf-2.0
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/gdk-pixbuf-2.0/gdk-pixbuf-xlib
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/contrib/gdk-pixbuf-xlib/gdk-pixbuf-xlib.h ${DESTDIR}${PREFIX}/include/gdk-pixbuf-2.0/gdk-pixbuf-xlib
	${INSTALL_DATA} ${WRKSRC}/contrib/gdk-pixbuf-xlib/gdk-pixbuf-xlibrgb.h ${DESTDIR}${PREFIX}/include/gdk-pixbuf-2.0/gdk-pixbuf-xlib
	${INSTALL_LIB} ${WRKSRC}/output/contrib/gdk-pixbuf-xlib/*.so* ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/output/meson-private/gdk-pixbuf-xlib-2.0.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../devel/py-meson/build.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+= glib2>=2.37.2
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection:=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
