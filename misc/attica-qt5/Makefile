# $NetBSD: Makefile,v 1.4 2017/02/12 06:24:46 ryoon Exp $

DISTNAME=	attica-${KF5VER}
PKGNAME=	${DISTNAME:S/-/-qt5-/}
PKGREVISION=	3
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Qt5 library that implements the Open Collaboration Services API
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

PKGCONFIG_OVERRIDE+=	src/cmake/libKF5Attica.pc.cmake

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
