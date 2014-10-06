# $NetBSD: Makefile,v 1.37 2014/10/06 19:46:59 roy Exp $
#

PKGNAME=		dhcpcd-gtk-${DHCPCD_UI_VERSION}
CATEGORIES=		net

DEPENDS+=		dhcpcd>=6.4.4:../../net/dhcpcd
DEPENDS+=		dhcpcd-icons:../../net/dhcpcd-icons

.include "../../net/dhcpcd-icons/Makefile.common"

USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	--with-gtk+

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
