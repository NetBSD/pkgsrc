# $NetBSD: Makefile,v 1.4 2016/03/05 11:29:03 jperkin Exp $
#

PKGNAME=		dhcpcd-qt-${DHCPCD_UI_VERSION}
PKGREVISION=		2
CATEGORIES=		net

COMMENT=		Qt system tray monitor for dhcpcd

DEPENDS+=	dhcpcd>=6.4.4:../../net/dhcpcd
DEPENDS+=	dhcpcd-icons>=${DHCPCD_UI_VERSION}:../../net/dhcpcd-icons

.include "../../net/dhcpcd-icons/Makefile.common"

USE_LANGUAGES=		c99 c++
CONFIGURE_ARGS+=	--with-qt
# Until I can get KDE4 to install...
CONFIGURE_ARGS+=	--disable-notification

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR:Q}

BUILDLINK_DEPMETHOD.qt4-tools=	build

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
