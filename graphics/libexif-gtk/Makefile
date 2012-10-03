# $NetBSD: Makefile,v 1.37.2.1 2012/10/03 12:08:08 spz Exp $

DISTNAME=	libexif-gtk-0.3.5
PKGREVISION=	16
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libexif/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libexif.sourceforge.net/
COMMENT=	EXIF file library (GTK2 interface)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	libexif-gtk/libexif-gtk.pc.in

# for libexif-0.6.13
SUBST_CLASSES+=			libexif-update
SUBST_STAGE.libexif-update=	pre-configure
SUBST_MESSAGE.libexif-update=	Fix configure script checks for libexif-0.6.13
SUBST_FILES.libexif-update=	configure
SUBST_SED.libexif-update=	s,exif-m,libexif/exif-m,g

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
