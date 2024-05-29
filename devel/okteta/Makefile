# $NetBSD: Makefile,v 1.52 2024/05/29 16:32:17 adam Exp $

DISTNAME=	okteta-0.26.13
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_KDE:=okteta/0.26.13/src/}

HOMEPAGE=	https://kde.org/applications/utilities/okteta/
COMMENT=	Hex Editor
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config

.include "../../devel/kcmutils/buildlink3.mk"
.include "../../devel/kparts/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../security/qca2-qt5/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
