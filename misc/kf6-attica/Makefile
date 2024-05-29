# $NetBSD: Makefile,v 1.2 2024/05/29 16:33:34 adam Exp $

DISTNAME=	attica-${KF6VER}
PKGREVISION=	1
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Qt5 library that implements the Open Collaboration Services API
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

PKGCONFIG_OVERRIDE+=		_KDE_build/src/KF6Attica.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
