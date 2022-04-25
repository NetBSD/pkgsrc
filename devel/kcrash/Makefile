# $NetBSD: Makefile,v 1.33 2022/04/25 03:50:34 markd Exp $

DISTNAME=	kcrash-${KF5VER}
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Support for application crash analysis and bug report from apps
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../x11/kwindowsystem/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
