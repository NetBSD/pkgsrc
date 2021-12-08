# $NetBSD: Makefile,v 1.31 2021/12/08 16:01:54 adam Exp $

DISTNAME=	kidletime-${KF5VER}
PKGREVISION=	2
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Monitoring user activity
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	pkg-config

.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
