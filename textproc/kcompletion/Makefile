# $NetBSD: Makefile,v 1.65 2024/06/07 23:55:47 markd Exp $

DISTNAME=	kcompletion-${KF5VER}
CATEGORIES=	textproc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Text completion helpers and widgets
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

.include "../../devel/kconfig/buildlink3.mk"
.include "../../x11/kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
