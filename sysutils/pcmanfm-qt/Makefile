# $NetBSD: Makefile,v 1.55 2026/04/28 08:42:48 pin Exp $

.include "../../meta-pkgs/lxqt/Makefile.common"

DISTNAME=	pcmanfm-qt-2.4.0
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/pcmanfm-qt/
COMMENT=	LXQt pcmanfm Qt frontend
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config perl

LDFLAGS.SunOS+=	-lsocket

AUTOSTART_CONF=		share/examples/autostart
SETTINGS_CONF=		share/examples/pcmanfm-qt/lxqt
PKG_SYSCONFSUBDIR=	xdg
MAKE_DIRS+=		${PKG_SYSCONFDIR}/autostart \
			${PKG_SYSCONFDIR}/pcmanfm-qt/lxqt

CONF_FILES+=		${AUTOSTART_CONF}/lxqt-desktop.desktop \
			${PKG_SYSCONFDIR}/autostart/lxqt-desktop.desktop
CONF_FILES+=		${SETTINGS_CONF}/settings.conf \
			${PKG_SYSCONFDIR}/pcmanfm-qt/lxqt/settings.conf

TOOL_DEPENDS+=	lxqt-build-tools>=2.4.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../devel/cmake/build.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/lxqt-menu-data/buildlink3.mk"
.include "../../x11/libfm-qt/buildlink3.mk"
.include "../../x11/liblxqt/buildlink3.mk"
.include "../../x11/plasma6-layer-shell-qt/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../x11/xcb-util-cursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
