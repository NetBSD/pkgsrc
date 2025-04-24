# $NetBSD: Makefile,v 1.101 2025/04/24 14:13:41 wiz Exp $

DISTNAME=	umbrello-${KAPPSVER}
PKGREVISION=	10
CATEGORIES=	devel

HOMEPAGE=	https://kde.org/applications/development/umbrello/
COMMENT=	UML Modeller
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

CMAKE_CONFIGURE_ARGS+=	-DBUILD_APIDOC=no

USE_TOOLS+=	msgmerge

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ktexteditor/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
