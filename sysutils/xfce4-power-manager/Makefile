# $NetBSD: Makefile,v 1.1 2018/05/18 17:07:29 youri Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-power-manager-1.6.1
CATEGORIES=	sysutils
MASTER_SITES=	http://archive.xfce.org/src/apps/xfce4-power-manager/1.6/

HOMEPAGE=	http://goodies.xfce.org/projects/applications/xfce4-power-manager
COMMENT=	Xfce power manager

CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFBASE}

CONF_FILES=	share/examples/xfce4/autostart/xfce4-power-manager.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/xfce4-power-manager.desktop

.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/upower/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../sysutils/consolekit/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
