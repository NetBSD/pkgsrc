# $NetBSD: Makefile,v 1.93 2026/05/14 16:41:34 ryoon Exp $

DISTNAME=	kturtle-${KAPPSVER}
PKGREVISION=	4
CATEGORIES=	misc

HOMEPAGE=	https://kde.org/applications/education/kturtle/
COMMENT=	KDE educational programming environment
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/kf6-kcrash/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../net/kf6-knewstuff/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
