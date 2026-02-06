# $NetBSD: Makefile,v 1.14 2026/02/06 10:04:33 wiz Exp $

.include "../../meta-pkgs/lxqt/Makefile.common"

DISTNAME=	libdbusmenu-lxqt-0.3.0
PKGREVISION=	4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/libdbusmenu-lxqt/
COMMENT=	Library providing a Qt implementation of the DBusMenu protocol
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}

PKGCONFIG_OVERRIDE+=	dbusmenu-lxqt.pc.in

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
