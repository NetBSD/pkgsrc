# $NetBSD: Makefile,v 1.7 2024/11/15 12:41:15 pin Exp $

DISTNAME=	libdbusmenu-lxqt-0.2.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/libdbusmenu-lxqt/
COMMENT=	Library providing a Qt implementation of the DBusMenu protocol
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}

PKGCONFIG_OVERRIDE+=	dbusmenu-lxqt.pc.in

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
