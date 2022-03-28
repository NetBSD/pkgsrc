# $NetBSD: Makefile,v 1.48 2022/03/28 10:53:00 tnn Exp $

DISTNAME=	knotifyconfig-${KF5VER}
PKGREVISION=	5
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
