# $NetBSD: Makefile,v 1.2 2024/05/29 16:34:36 adam Exp $

DISTNAME=	kcompletion-${KF6VER}
PKGREVISION=	1
CATEGORIES=	textproc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Text completion helpers and widgets
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

.include "../../devel/kf6-kconfig/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt6-qttools= build
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../textproc/kf6-kcodecs/buildlink3.mk"
.include "../../x11/kf6-kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
