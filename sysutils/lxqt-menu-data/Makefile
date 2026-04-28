# $NetBSD: Makefile,v 1.20 2026/04/28 07:54:39 pin Exp $

.include "../../meta-pkgs/lxqt/Makefile.common"

DISTNAME=	lxqt-menu-data-2.4.0
CATEGORIES=	sysutils x11

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-menu-data/
COMMENT=	freedesktop.org compliant menu files for LXQt
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config perl

MENU_CONF=		share/examples/menus
PKG_SYSCONFSUBDIR=	xdg
MAKE_DIRS=		${PKG_SYSCONFDIR}/menus

CONF_FILES=	${MENU_CONF}/lxqt-applications.menu \
		${PKG_SYSCONFDIR}/menus/lxqt-applications.menu
CONF_FILES+=	${MENU_CONF}/lxqt-applications-compact.menu \
		${PKG_SYSCONFDIR}/menus/lxqt-applications-compact.menu
CONF_FILES+=	${MENU_CONF}/lxqt-applications-fm.menu \
		${PKG_SYSCONFDIR}/menus/lxqt-applications-fm.menu
CONF_FILES+=	${MENU_CONF}/lxqt-config.menu \
		${PKG_SYSCONFDIR}/menus/lxqt-config.menu
CONF_FILES+=	${MENU_CONF}/lxqt-panel-applications.menu \
		${PKG_SYSCONFDIR}/menus/lxqt-panel-applications.menu

TOOL_DEPENDS+=	lxqt-build-tools>=2.4.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

BUILDLINK_API_DEPENDS.qt6-qtbase+=	qt6-qtbase>=6.6.0
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
