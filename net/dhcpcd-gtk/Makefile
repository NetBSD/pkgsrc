# $NetBSD: Makefile,v 1.53 2021/12/08 16:05:55 adam Exp $
#

PKGNAME=		dhcpcd-gtk-${DHCPCD_UI_VERSION}
PKGREVISION=		14
CATEGORIES=		net

COMMENT=		GTK+ system tray monitor for dhcpcd

DEPENDS+=	dhcpcd>=6.4.4:../../net/dhcpcd
DEPENDS+=	dhcpcd-icons>=${DHCPCD_UI_VERSION}:../../net/dhcpcd-icons

.include "../../net/dhcpcd-icons/Makefile.common"

USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	--with-gtk+
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
MAKEFLAGS+=		SYSCONFDIR=${EGDIR}

CONF_FILES=		${EGDIR}/xdg/autostart/${PKGBASE}.desktop \
			${PKG_SYSCONFDIR}/xdg/autostart/${PKGBASE}.desktop
MAKE_DIRS+=		${PKG_SYSCONFDIR}/xdg/autostart

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
