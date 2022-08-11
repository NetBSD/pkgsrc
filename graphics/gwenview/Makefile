# $NetBSD: Makefile,v 1.120 2022/08/11 05:08:42 gutteridge Exp $

DISTNAME=	gwenview-${KAPPSVER}
PKGREVISION=	8
CATEGORIES=	graphics

HOMEPAGE=	https://kde.org/applications/graphics/org.kde.gwenview/
COMMENT=	KDE image viewer
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools
DEPENDS+=	kimageformats>=5.19.0:../../graphics/kimageformats

USE_TOOLS+=	msgmerge pkg-config

REPLACE_PERL=	kconf_update/gwenview-imageview-alphabackgroundmode-update.pl

.include "../../devel/cfitsio/buildlink3.mk"
.include "../../devel/kitemmodels/buildlink3.mk"
.include "../../devel/kparts/buildlink3.mk"
.include "../../devel/purpose/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/libkdcraw/buildlink3.mk"
.include "../../graphics/libkipi/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/baloo5/buildlink3.mk"
.include "../../x11/kactivities5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtimageformats/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
