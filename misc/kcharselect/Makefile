# $NetBSD: Makefile,v 1.89 2026/01/07 08:47:56 wiz Exp $

DISTNAME=	kcharselect-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	misc

HOMEPAGE=	https://kde.org/applications/utilities/kcharselect/
COMMENT=	KDE character selector
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/kf6-kbookmarks/buildlink3.mk"
.include "../../devel/kf6-kcrash/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
