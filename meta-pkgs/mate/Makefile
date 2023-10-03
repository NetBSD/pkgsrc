# $NetBSD: Makefile,v 1.45 2023/10/03 21:54:06 gutteridge Exp $

PKGNAME=	mate-${VERSION}
CATEGORIES=	meta-pkgs

COMMENT=	Meta-package for MATE desktop environment

META_PACKAGE=	yes

.include "../../meta-pkgs/mate/Makefile.common"

DEPENDS+=	atril>=${VERSION:R}.1:../../print/atril
DEPENDS+=	caja>=${VERSION:R}.1:../../sysutils/caja
DEPENDS+=	caja-dropbox>=${VERSION}:../../sysutils/caja-dropbox
DEPENDS+=	caja-extensions>=${VERSION:R}.1:../../sysutils/caja-extensions
DEPENDS+=	engrampa>=${VERSION:R}.1:../../archivers/engrampa
DEPENDS+=	eom>=${VERSION:R}.1:../../graphics/eom
DEPENDS+=	libmatekbd>=${VERSION:R}.1:../../x11/libmatekbd
DEPENDS+=	libmatemixer>=${VERSION:R}.1:../../audio/libmatemixer
DEPENDS+=	libmateweather>=${VERSION:R}.1:../../misc/libmateweather
DEPENDS+=	marco>=${VERSION:R}.2:../../wm/marco
DEPENDS+=	mate-applets>=${VERSION:R}.1:../../x11/mate-applets
DEPENDS+=	mate-backgrounds>=${VERSION}:../../graphics/mate-backgrounds
DEPENDS+=	mate-calc>=${VERSION}:../../misc/mate-calc
DEPENDS+=	mate-common>=${VERSION}:../../devel/mate-common
DEPENDS+=	mate-control-center>=${VERSION:R}.1:../../x11/mate-control-center
DEPENDS+=	mate-desktop>=${VERSION:R}.2:../../x11/mate-desktop
DEPENDS+=	mate-icon-theme>=${VERSION}:../../graphics/mate-icon-theme
DEPENDS+=	mate-icon-theme-faenza>=1.20.0:../../graphics/mate-icon-theme-faenza
DEPENDS+=	mate-indicator-applet>=${VERSION}:../../x11/mate-indicator-applet
DEPENDS+=	mate-media>=${VERSION:R}.1:../../multimedia/mate-media
DEPENDS+=	mate-menus>=${VERSION:R}.1:../../x11/mate-menus
DEPENDS+=	mate-netbook>=${VERSION}:../../wm/mate-netbook
DEPENDS+=	mate-notification-daemon>=${VERSION:R}.1:../../sysutils/mate-notification-daemon
DEPENDS+=	mate-panel>=${VERSION:R}.3:../../x11/mate-panel
DEPENDS+=	mate-polkit>=${VERSION:R}.1:../../security/mate-polkit
DEPENDS+=	mate-power-manager>=${VERSION:R}.1:../../sysutils/mate-power-manager
DEPENDS+=	mate-screensaver>=${VERSION:R}.2:../../x11/mate-screensaver
DEPENDS+=	mate-sensors-applet>=${VERSION}:../../sysutils/mate-sensors-applet
DEPENDS+=	mate-session-manager>=${VERSION:R}.1:../../x11/mate-session-manager
DEPENDS+=	mate-settings-daemon>=${VERSION:R}.1:../../x11/mate-settings-daemon
#DEPENDS+=	mate-system-monitor>=1.22.2:../../sysutils/mate-system-monitor
DEPENDS+=	mate-terminal>=${VERSION:R}.1:../../x11/mate-terminal
DEPENDS+=	mate-themes>=3.22.24:../../graphics/mate-themes
#DEPENDS+=	mate-user-share>=${VERSION}:../../net/mate-user-share
DEPENDS+=	mate-utils>=${VERSION:R}.1:../../misc/mate-utils
DEPENDS+=	mozo>=${VERSION:R}.2:../../x11/mozo
DEPENDS+=	pluma>=${VERSION:R}.1:../../editors/pluma

.include "../../mk/bsd.pkg.mk"
