# $NetBSD: Makefile,v 1.67 2025/12/21 11:53:59 markd Exp $

DISTNAME=	libkmahjongg-${KAPPSVER}
CATEGORIES=	games

HOMEPAGE=	https://www.kde.org/applications/games/
COMMENT=	Library for loading and rendering of Mahjongg tilesets
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../textproc/kf6-kcompletion/buildlink3.mk"
.include "../../x11/kf6-kconfigwidgets/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
