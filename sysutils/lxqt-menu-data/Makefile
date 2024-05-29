# $NetBSD: Makefile,v 1.3 2024/05/29 16:34:28 adam Exp $

DISTNAME=	lxqt-menu-data-1.4.1
PKGREVISION=	2
CATEGORIES=	sysutils x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-menu-data/
COMMENT=	freedesktop.org compliant menu files for LXQt
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

MENU_CONF=		share/examples/menus
PKG_SYSCONFSUBDIR=	xdg
MAKE_DIRS=		${PKG_SYSCONFDIR}/menus

CONF_FILES=	${MENU_CONF}/lxqt-applications.menu \
		${PKG_SYSCONFDIR}/menus/lxqt-applications.menu
CONF_FILES+=	${MENU_CONF}/lxqt-applications-compact.menu \
		${PKG_SYSCONFDIR}/menus/lxqt-applications-compact.menu
CONF_FILES+=	${MENU_CONF}/lxqt-applications-simple.menu \
		${PKG_SYSCONFDIR}/menus/lxqt-applications-simple.menu
CONF_FILES+=	${MENU_CONF}/lxqt-applications-fm.menu \
		${PKG_SYSCONFDIR}/menus/lxqt-applications-fm.menu
CONF_FILES+=	${MENU_CONF}/lxqt-config.menu \
		${PKG_SYSCONFDIR}/menus/lxqt-config.menu

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	lxqt-build-tools>=0.13.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

BUILDLINK_API_DEPENDS.qt5-qtbase+=	qt5-qtbase>=5.15.0
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
