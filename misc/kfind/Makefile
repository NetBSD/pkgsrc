# $NetBSD: Makefile,v 1.14 2025/04/17 21:51:38 wiz Exp $

DISTNAME=	kfind-${KAPPSVER}
PKGREVISION=	8
CATEGORIES=	misc

HOMEPAGE=	https://www.kde.org/applications/utilities/kfind/
COMMENT=	KDE Find Files/Folders
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/kio/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/kfilemetadata5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
