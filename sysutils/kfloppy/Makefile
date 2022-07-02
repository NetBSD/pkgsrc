# $NetBSD: Makefile,v 1.62 2022/07/02 16:53:35 ryoon Exp $

DISTNAME=	kfloppy-${KAPPSVER}
PKGREVISION=	7
CATEGORIES=	sysutils

HOMEPAGE=	https://kde.org/applications/utilities/kfloppy/
COMMENT=	KDE floppy formatter
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kxmlgui/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
