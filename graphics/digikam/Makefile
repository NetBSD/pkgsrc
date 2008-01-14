# $NetBSD: Makefile,v 1.38 2008/01/14 23:19:52 wiz Exp $

DISTNAME=		digikam-0.9.3
CATEGORIES=		graphics kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=digikam/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.digikam.org/
COMMENT=		Advanced digital photo management application for KDE

USE_TOOLS+=		gmake msgfmt perl:run pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

REPLACE_PERL+=		digikam/utilities/scripts/digitaglinktree

BUILDLINK_API_DEPENDS.imlib2+=	imlib2>=1.2
BUILDLINK_API_DEPENDS.kdelibs+=	kdelibs>=3.5.2
BUILDLINK_API_DEPENDS.libkexiv2+=	libkexiv2>=0.1.6
BUILDLINK_API_DEPENDS.libkdcraw+=	libkdcraw>=0.1.2

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/libkdcraw/buildlink3.mk"
.include "../../graphics/libkexiv2/buildlink3.mk"
.include "../../graphics/libkipi/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
