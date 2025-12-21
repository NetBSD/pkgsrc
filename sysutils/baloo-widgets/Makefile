# $NetBSD: Makefile,v 1.64 2025/12/21 19:27:53 markd Exp $

DISTNAME=	baloo-widgets-${KAPPSVER}
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
