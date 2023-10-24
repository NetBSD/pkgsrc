# $NetBSD: Makefile,v 1.2 2023/10/24 22:11:18 wiz Exp $

DISTNAME=	ktextaddons-1.3.2
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_KDE:=ktextaddons/}

HOMEPAGE=	https://invent.kde.org/libraries/ktextaddons
COMMENT=	Various text handling addons
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2 AND modified-bsd

.include "../../meta-pkgs/kde/applications.mk"

CMAKE_ARGS+=	-DKF_IGNORE_PLATFORM_CHECK=true

USE_TOOLS+=	msgmerge

.include "../../archivers/karchive/buildlink3.mk"
.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../devel/ki18n/buildlink3.mk"
.include "../../security/qt5-qtkeychain/buildlink3.mk"
.include "../../x11/kconfigwidgets/buildlink3.mk"
.include "../../x11/kxmlgui/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
