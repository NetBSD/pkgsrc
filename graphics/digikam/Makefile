# $NetBSD: Makefile,v 1.31 2007/01/17 23:47:19 wiz Exp $

DISTNAME=		digikam-0.9.0
PKGREVISION=		2
CATEGORIES=		graphics kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=digikam/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.digikam.org/
COMMENT=		KDE frontend to gphoto2

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake msgfmt perl:run pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

REPLACE_PERL+=		digikam/utilities/scripts/digitaglinktree

BUILDLINK_API_DEPENDS.imlib2+=	imlib2>=1.2
BUILDLINK_API_DEPENDS.kdelibs+=	kdelibs>=3.5.2
BUILDLINK_API_DEPENDS.exiv2+=	exiv2>=0.12

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/libkexif/buildlink3.mk"
.include "../../graphics/libkipi/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
