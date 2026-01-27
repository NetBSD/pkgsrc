# $NetBSD: Makefile,v 1.155 2026/01/27 08:39:42 wiz Exp $

DISTNAME=	gwenview-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	graphics

HOMEPAGE=	https://kde.org/applications/graphics/org.kde.gwenview/
COMMENT=	KDE image viewer
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools
DEPENDS+=	kf6-kimageformats>=6.18.0:../../graphics/kf6-kimageformats

USE_TOOLS+=	msgmerge pkg-config

#REPLACE_PERL=	kconf_update/gwenview-imageview-alphabackgroundmode-update.pl

.include "../../devel/cfitsio/buildlink3.mk"
.include "../../devel/kf6-kitemmodels/buildlink3.mk"
.include "../../devel/kf6-kparts/buildlink3.mk"
.include "../../devel/kf6-purpose/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/kimageannotator/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libkdcraw/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qt6-qtimageformats/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/kf6-baloo/buildlink3.mk"
.include "../../x11/plasma6-plasma-activities/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
