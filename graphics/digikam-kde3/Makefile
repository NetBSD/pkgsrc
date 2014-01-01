# $NetBSD: Makefile,v 1.37 2014/01/01 11:52:19 wiz Exp $

DISTNAME=		digikam-0.9.6
PKGREVISION=		32
CATEGORIES=		graphics kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=digikam/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.digikam.org/
COMMENT=		Advanced digital photo management application (KDE3)
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		gmake msgfmt perl:run pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--without-included-sqlite3

REPLACE_PERL+=		digikam/utilities/scripts/digitaglinktree

PLIST_SUBST=	HTMLDIR=${DISTNAME}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/libkdcraw-kde3/buildlink3.mk"
.include "../../graphics/libkexiv2-kde3/buildlink3.mk"
.include "../../graphics/libkipi-kde3/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

BUILDLINK_API_DEPENDS.imlib2+=	imlib2>=1.2
BUILDLINK_API_DEPENDS.kdelibs+=	kdelibs>=3.5.2
BUILDLINK_API_DEPENDS.libkexiv2+=	libkexiv2>=0.1.6
BUILDLINK_API_DEPENDS.libkdcraw+=	libkdcraw>=0.1.6

.include "../../mk/bsd.pkg.mk"
