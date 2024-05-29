# $NetBSD: Makefile,v 1.2 2024/05/29 16:33:55 adam Exp $

DISTNAME=	knewstuff-${KF6VER}
PKGREVISION=	1
CATEGORIES=	net

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Support for downloading application assets from the network
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

USE_TOOLS+=	msgmerge

.include "../../archivers/kf6-karchive/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kpackage/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../misc/kf6-attica/buildlink3.mk"
.include "../../www/kf6-syndication/buildlink3.mk"
.include "../../x11/kf6-kirigami/buildlink3.mk"
.include "../../x11/kf6-kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
