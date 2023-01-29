# $NetBSD: Makefile,v 1.56 2023/01/29 21:14:26 ryoon Exp $

DISTNAME=	kcmutils-${KF5VER}
PKGREVISION=	2
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Utilities for interacting with KCModules
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	msgmerge

.include "../../meta-pkgs/kde/kf5.mk"

.include "../../devel/kdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
