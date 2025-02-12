# $NetBSD: Makefile,v 1.13 2025/02/12 06:45:20 ryoon Exp $

DISTNAME=	keditbookmarks-${KAPPSVER}
PKGREVISION=	7
CATEGORIES=	misc

HOMEPAGE=	https://www.kde.org/
COMMENT=	KDE Bookmark Organizer and Editor
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/kparts/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
