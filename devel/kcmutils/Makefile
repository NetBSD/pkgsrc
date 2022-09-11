# $NetBSD: Makefile,v 1.53 2022/09/11 12:51:05 wiz Exp $

DISTNAME=	kcmutils-${KF5VER}
PKGREVISION=	3
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Utilities for interacting with KCModules
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	msgmerge

.include "../../meta-pkgs/kde/kf5.mk"

.include "../../devel/kdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
