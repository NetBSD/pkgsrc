# $NetBSD: Makefile,v 1.87 2025/02/12 06:45:21 ryoon Exp $

DISTNAME=	kiten-${KAPPSVER}
PKGREVISION=	7
CATEGORIES=	misc

HOMEPAGE=	https://kde.org/applications/education/kiten/
COMMENT=	KDE Japanese reference/learning tool
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/khtml/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
