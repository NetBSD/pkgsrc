# $NetBSD: Makefile,v 1.1 2016/05/26 08:51:12 markd Exp $

DISTNAME=	attica-${KF5VER}
PKGNAME=	${DISTNAME:S/-/-qt5-/}
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Qt5 library that implements the Open Collaboration Services API
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

PKGCONFIG_OVERRIDE+=	src/cmake/libKF5Attica.pc.cmake

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
