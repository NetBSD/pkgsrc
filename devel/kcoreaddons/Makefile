# $NetBSD: Makefile,v 1.23 2018/04/14 07:33:54 adam Exp $

DISTNAME=	kcoreaddons-${KF5VER}
PKGREVISION=	1
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Addons to QtCore
LICENSE=	gnu-lgpl-v2 AND gnu-lgpl-v2.1 AND modified-bsd

.include "../../meta-pkgs/kde/kf5.mk"

.if ${OPSYS} != "SunOS"
.include "../../devel/libinotify/buildlink3.mk"
.endif

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../mk/fam.buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
