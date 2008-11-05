# $NetBSD: Makefile,v 1.37 2008/11/05 19:21:45 wiz Exp $

DISTNAME=	kipi-plugins-0.1.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kipi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kipi-plugins.org/drupal/
COMMENT=	Kipi (KDE Image Plugin Interface) plugins

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake perl pkg-config msgfmt bash:run
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	# empty

REPLACE_BASH=		kipi-plugins/mpegencoder/images2mpg

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../audio/libgpod/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
BUILDLINK_API_DEPENDS.libkdcraw+=	libkdcraw>=0.1.4
.include "../../graphics/libkdcraw/buildlink3.mk"
.include "../../graphics/libkexiv2/buildlink3.mk"
.include "../../graphics/libkipi/buildlink3.mk"
.include "../../multimedia/mjpegtools/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
