# $NetBSD: Makefile,v 1.6 2019/10/29 12:39:13 kamil Exp $
#

PKGNAME=		dhcpcd-qt-${DHCPCD_UI_VERSION}
PKGREVISION=		4
CATEGORIES=		net

COMMENT=		Qt system tray monitor for dhcpcd

DEPENDS+=	dhcpcd>=6.4.4:../../net/dhcpcd
DEPENDS+=	dhcpcd-icons>=${DHCPCD_UI_VERSION}:../../net/dhcpcd-icons

.include "../../net/dhcpcd-icons/Makefile.common"

USE_LANGUAGES=		c99 c++
CONFIGURE_ARGS+=	--with-qt
CONFIGURE_ARGS+=	--disable-notification

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR:Q}

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
