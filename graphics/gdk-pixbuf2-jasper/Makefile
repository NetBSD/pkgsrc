# $NetBSD: Makefile,v 1.14 2013/01/26 21:37:47 adam Exp $
#

DISTNAME=	gdk-pixbuf-${PIXBUF2_VERSION}
PKGNAME=	gdk-pixbuf2-jasper-${PIXBUF2_VERSION}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gdk-pixbuf/${MSITE_VERSION}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.gnome.org/pub/gnome/sources/gdk-pixbuf/2.24/
COMMENT=	Image loaders for gtk2 - jasper module
LICENSE=	gnu-gpl-v2

DISTINFO_FILE=	${.CURDIR}/../../graphics/gdk-pixbuf2/distinfo
PATCHDIR=	${.CURDIR}/../../graphics/gdk-pixbuf2/patches

.include "../../graphics/gdk-pixbuf2/Makefile.version"

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
