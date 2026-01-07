# $NetBSD: Makefile,v 1.2 2026/01/07 08:48:56 wiz Exp $

DISTNAME=	kmenuedit-${PLASMAVER}
PKGREVISION=	1
CATEGORIES=	sysutils

HOMEPAGE=	https://kde.org/plasma-desktop/
COMMENT=	KDE menu editor
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/plasma6.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../textproc/kf6-sonnet/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
