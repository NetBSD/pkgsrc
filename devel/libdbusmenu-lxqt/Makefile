# $NetBSD: Makefile,v 1.22 2026/11/15 02:05:52 gutteridge Exp $

.include "../../meta-pkgs/lxqt/Makefile.common"

DISTNAME=	libdbusmenu-lxqt-0.5.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/libdbusmenu-lxqt/
COMMENT=	Library providing a Qt implementation of the DBusMenu protocol
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

TOOL_DEPENDS+=	lxqt-build-tools>=2.5.0:../../devel/lxqt-build-tools

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}

PKGCONFIG_OVERRIDE+=	dbusmenu-lxqt.pc.in

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
