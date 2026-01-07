# $NetBSD: Makefile,v 1.82 2026/01/07 08:48:05 wiz Exp $

DISTNAME=	dragon-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	multimedia

HOMEPAGE=	https://apps.kde.org/dragonplayer/
COMMENT=	Simple video player for KDE
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge pkg-config

.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/kf6-kparts/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/ffmpeg7/buildlink3.mk"
.include "../../multimedia/qt6-qtmultimedia/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kf6-kirigami/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
