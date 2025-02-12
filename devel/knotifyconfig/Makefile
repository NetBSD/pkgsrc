# $NetBSD: Makefile,v 1.81 2025/02/12 06:44:38 ryoon Exp $

DISTNAME=	knotifyconfig-${KF5VER}
PKGREVISION=	8
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Configuration system for KNotify
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	msgmerge

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
