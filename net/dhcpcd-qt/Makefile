# $NetBSD: Makefile,v 1.14 2020/06/02 08:24:30 adam Exp $
#

PKGNAME=		dhcpcd-qt-${DHCPCD_UI_VERSION}
PKGREVISION=		10
CATEGORIES=		net

COMMENT=		Qt system tray monitor for dhcpcd

DEPENDS+=	dhcpcd>=6.4.4:../../net/dhcpcd
DEPENDS+=	dhcpcd-icons>=${DHCPCD_UI_VERSION}:../../net/dhcpcd-icons

.include "../../net/dhcpcd-icons/Makefile.common"

USE_LANGUAGES=		c99 c++
CONFIGURE_ARGS+=	--with-qt
CONFIGURE_ARGS+=	--disable-notification

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR:Q}
EGDIR=                  ${PREFIX}/share/examples/${PKGBASE}
MAKEFLAGS+=             SYSCONFDIR=${EGDIR}

CONF_FILES=             ${EGDIR}/xdg/autostart/${PKGBASE}.desktop \
                        ${PKG_SYSCONFDIR}/xdg/autostart/${PKGBASE}.desktop
MAKE_DIRS+=             ${PKG_SYSCONFDIR}/xdg/autostart

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
