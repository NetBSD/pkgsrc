# $NetBSD: Makefile,v 1.24 2007/01/17 23:47:20 wiz Exp $

DISTNAME=	kipi-plugins-0.1.3-rc1
PKGNAME=	${DISTNAME:S/-rc/rc/}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kipi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://extragear.kde.org/apps/kipi/
COMMENT=	Kipi (KDE Image Plugin Interface) plugins

DEPENDS+=	dcraw-[0-9]*:../../graphics/dcraw

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake pkg-config msgfmt bash:run
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	# empty

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/libkexif/buildlink3.mk"
.include "../../graphics/libkipi/buildlink3.mk"
.include "../../multimedia/mjpegtools/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
