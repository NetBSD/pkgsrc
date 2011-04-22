# $NetBSD: Makefile,v 1.2 2011/04/22 13:42:16 obache Exp $
#

DISTNAME=	gdk-pixbuf-2.22.1
PKGNAME=	gdk-pixbuf2-xlib-2.22.1
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gdk-pixbuf/2.22/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.gnome.org/pub/gnome/sources/gdk-pixbuf/2.22/
COMMENT=	Image loaders for gtk2
LICENSE=	gnu-gpl-v2

PATCHDIR=	${.CURDIR}/../../graphics/gdk-pixbuf2/patches
DISTINFO_FILE=	${.CURDIR}/../../graphics/gdk-pixbuf2/distinfo
BUILD_DIRS=	contrib/gdk-pixbuf-xlib
INSTALL_DIRS=	contrib/gdk-pixbuf-xlib

CONFLICTS+=	gtk2+<2.22
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-libtiff --without-libjpeg --without-libpng
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	contrib/gdk-pixbuf-xlib/gdk-pixbuf-xlib-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gdk-pixbuf-2.0.pc.in

.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+= glib2>=2.26.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
