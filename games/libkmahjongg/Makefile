# $NetBSD: Makefile,v 1.43 2021/04/07 12:28:22 markd Exp $

DISTNAME=	libkmahjongg-${KAPPSVER}
CATEGORIES=	games

HOMEPAGE=	https://www.kde.org/applications/games/
COMMENT=	Library for loading and rendering of Mahjongg tilesets
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../textproc/kcompletion/buildlink3.mk"
.include "../../x11/kconfigwidgets/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
