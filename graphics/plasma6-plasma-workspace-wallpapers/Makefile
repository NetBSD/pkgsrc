# $NetBSD: Makefile,v 1.1 2025/12/23 21:49:08 markd Exp $

DISTNAME=	plasma-workspace-wallpapers-${PLASMAVER}
CATEGORIES=	graphics

HOMEPAGE=	https://kde.org/plasma-desktop/
COMMENT=	Additional wallpapers for the Plasma Workspace
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v3

.include "../../meta-pkgs/kde/plasma6.mk"

CMAKE_CONFIGURE_ARGS+=	-DBUILD_WITH_QT6=ON

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
