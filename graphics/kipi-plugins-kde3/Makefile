# $NetBSD: Makefile,v 1.23.2.1 2012/10/03 12:08:07 spz Exp $

DISTNAME=	kipi-plugins-0.1.7
PKGREVISION=	23
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kipi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kipi-plugins.org/drupal/
COMMENT=	Kipi (KDE Image Plugin Interface) plugins (KDE3)
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake perl pkg-config msgfmt bash:run
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	# empty

REPLACE_BASH=		kipi-plugins/mpegencoder/images2mpg

DEPENDS+=	ImageMagick>=5.5.4:../../graphics/ImageMagick

.include "../../meta-pkgs/kde3/kde3.mk"
BUILDLINK_API_DEPENDS.libgpod+=	libgpod>=0.7.0
.include "../../audio/libgpod/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
BUILDLINK_API_DEPENDS.libkdcraw+=	libkdcraw>=0.1.4<4.0
.include "../../graphics/libkdcraw-kde3/buildlink3.mk"
.include "../../graphics/libkexiv2-kde3/buildlink3.mk"
.include "../../graphics/libkipi-kde3/buildlink3.mk"
.include "../../multimedia/mjpegtools/buildlink3.mk"
# gdk from gtk2 is needed for libgpod artwork support
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.10.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
