# $NetBSD: Makefile,v 1.17 2026/01/07 08:49:04 wiz Exp $

DISTNAME=	ktextaddons-1.8.0
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_KDE:=ktextaddons/}

HOMEPAGE=	https://invent.kde.org/libraries/ktextaddons
COMMENT=	Various text handling addons
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2 AND modified-bsd

.include "../../meta-pkgs/kde/applications.mk"

CMAKE_CONFIGURE_ARGS+=	-DKF_IGNORE_PLATFORM_CHECK=true

USE_TOOLS+=	msgmerge

.include "../../archivers/kf6-karchive/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../security/qt6-qtkeychain/buildlink3.mk"
.include "../../textproc/kf6-syntax-highlighting/buildlink3.mk"
.include "../../x11/kf6-kconfigwidgets/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
