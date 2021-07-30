# $NetBSD: Makefile,v 1.69 2021/07/30 12:26:46 ryoon Exp $

DISTNAME=	umbrello-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	devel

HOMEPAGE=	https://kde.org/applications/development/umbrello/
COMMENT=	UML Modeller
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

CMAKE_ARGS+=	-DBUILD_APIDOC=no

USE_TOOLS+=	msgmerge

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ktexteditor/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4support/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
