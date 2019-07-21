# $NetBSD: Makefile,v 1.47 2019/07/21 22:25:29 wiz Exp $
#

PKGNAME=		dhcpcd-gtk-${DHCPCD_UI_VERSION}
PKGREVISION=		9
CATEGORIES=		net

COMMENT=		GTK+ system tray monitor for dhcpcd

DEPENDS+=	dhcpcd>=6.4.4:../../net/dhcpcd
DEPENDS+=	dhcpcd-icons>=${DHCPCD_UI_VERSION}:../../net/dhcpcd-icons

.include "../../net/dhcpcd-icons/Makefile.common"

USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	--with-gtk+

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
