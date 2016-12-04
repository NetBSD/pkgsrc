# $NetBSD: Makefile,v 1.7 2016/12/04 05:17:05 ryoon Exp $

DISTNAME=	kcoreaddons-${KF5VER}
PKGREVISION=	1
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Addons to QtCore
LICENSE=	gnu-lgpl-v2 AND gnu-lgpl-v2.1 AND modified-bsd

.include "../../meta-pkgs/kf5/Makefile.common"

#CMAKE_ARGS+=	-DENABLE_INOTIFY=OFF

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../mk/fam.buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
