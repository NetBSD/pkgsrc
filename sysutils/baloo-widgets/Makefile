# $NetBSD: Makefile,v 1.66 2026/01/27 08:40:32 wiz Exp $

DISTNAME=	baloo-widgets-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	sysutils

HOMEPAGE=	https://community.kde.org/Baloo
COMMENT=	Widgets for Baloo
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=5.19.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

.include "../../sysutils/kf6-baloo/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
