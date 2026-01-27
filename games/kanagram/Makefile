# $NetBSD: Makefile,v 1.91 2026/01/27 08:39:30 wiz Exp $

DISTNAME=	kanagram-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	games

HOMEPAGE=	https://kde.org/applications/education/kanagram/
COMMENT=	KDE letter order game
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/kf6-kdeclarative/buildlink3.mk"
.include "../../misc/libkeduvocdocument/buildlink3.mk"
.include "../../net/kf6-knewstuff/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
