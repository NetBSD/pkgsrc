# $NetBSD: Makefile,v 1.4 2024/08/02 16:58:58 pin Exp $

DISTNAME=	lxqt-menu-data-2.0.0
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

TOOL_DEPENDS+=	lxqt-build-tools>=2.0.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

BUILDLINK_API_DEPENDS.qt5-qtbase+=	qt6-qtbase>=6.6.0
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
