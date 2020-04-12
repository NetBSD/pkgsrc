# $NetBSD: Makefile,v 1.27 2020/04/12 08:28:00 adam Exp $

DISTNAME=	attica-${KF5VER}
PKGNAME=	${DISTNAME:S/-/-qt5-/}
PKGREVISION=	3
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Qt5 library that implements the Open Collaboration Services API
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

PKGCONFIG_OVERRIDE+=	src/cmake/libKF5Attica.pc.cmake

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
