# $NetBSD: Makefile,v 1.18 2026/01/07 08:47:57 wiz Exp $

DISTNAME=	keditbookmarks-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	misc

HOMEPAGE=	https://www.kde.org/
COMMENT=	KDE Bookmark Organizer and Editor
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/kf6-kparts/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
