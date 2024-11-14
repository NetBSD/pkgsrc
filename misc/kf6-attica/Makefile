# $NetBSD: Makefile,v 1.5 2024/11/14 22:20:48 wiz Exp $

DISTNAME=	attica-${KF6VER}
PKGREVISION=	4
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Qt5 library that implements the Open Collaboration Services API
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

PKGCONFIG_OVERRIDE+=		_KDE_build/src/KF6Attica.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
