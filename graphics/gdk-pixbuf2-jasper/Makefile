# $NetBSD: Makefile,v 1.11 2012/09/15 10:04:51 obache Exp $
#

DISTNAME=	gdk-pixbuf-2.26.3
PKGNAME=	gdk-pixbuf2-jasper-2.26.3
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gdk-pixbuf/2.26/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.gnome.org/pub/gnome/sources/gdk-pixbuf/2.24/
COMMENT=	Image loaders for gtk2 - jasper module
LICENSE=	gnu-gpl-v2

DISTINFO_FILE=	${.CURDIR}/../../graphics/gdk-pixbuf2/distinfo
PATCHDIR=	${.CURDIR}/../../graphics/gdk-pixbuf2/patches

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-libtiff --without-libjpeg --without-libpng
CONFIGURE_ARGS+=	--with-libjasper
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

BUILD_DIRS=	gdk-pixbuf
BUILD_TARGET=	libpixbufloader-jasper.la

do-install:
	${INSTALL_DATA_DIR} \
	${DESTDIR}${PREFIX}/lib/gdk-pixbuf-2.0/2.10.0/loaders
	cd ${WRKSRC}/gdk-pixbuf && ${LIBTOOL} --mode=install \
	${INSTALL_DATA} libpixbufloader-jasper.la \
	${DESTDIR}${PREFIX}/lib/gdk-pixbuf-2.0/2.10.0/loaders

.include "../../graphics/gdk-pixbuf2/loaders.mk"

BUILDLINK_API_DEPENDS.glib2+= glib2>=2.26.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
