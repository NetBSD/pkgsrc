# $NetBSD: Makefile,v 1.27 2006/11/29 12:02:10 xtraeme Exp $

DISTNAME=		digikam-0.9.0-rc1
PKGNAME=		${DISTNAME:S/-rc/rc/}
CATEGORIES=		graphics kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=digikam/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.digikam.org/
COMMENT=		KDE frontend to gphoto2

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake msgfmt perl pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

BUILDLINK_API_DEPENDS.imlib2+=	imlib2>=1.2
BUILDLINK_API_DEPENDS.kdelibs+=	kdelibs>=3.5.2
BUILDLINK_API_DEPENDS.exiv2+=	exiv2>=0.12

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/libkexif/buildlink3.mk"
.include "../../graphics/libkipi/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
