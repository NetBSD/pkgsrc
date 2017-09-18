# $NetBSD: Makefile,v 1.6 2017/09/18 09:53:01 maya Exp $

DISTNAME=	attica-${KF5VER}
PKGNAME=	${DISTNAME:S/-/-qt5-/}
PKGREVISION=	5
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Qt5 library that implements the Open Collaboration Services API
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

PKGCONFIG_OVERRIDE+=	src/cmake/libKF5Attica.pc.cmake

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
