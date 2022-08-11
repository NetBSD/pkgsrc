# $NetBSD: Makefile,v 1.38 2022/08/11 05:09:00 gutteridge Exp $

PKGNAME=	mate-${VERSION}
PKGREVISION=	3
CATEGORIES=	meta-pkgs

COMMENT=	Meta-package for MATE desktop environment

META_PACKAGE=	yes

.include "../../meta-pkgs/mate/Makefile.common"

DEPENDS+=	atril>=${VERSION}:../../print/atril
DEPENDS+=	caja>=${VERSION}:../../sysutils/caja
DEPENDS+=	caja-dropbox>=${VERSION:R}.0:../../sysutils/caja-dropbox
DEPENDS+=	caja-extensions>=${VERSION}:../../sysutils/caja-extensions
DEPENDS+=	engrampa>=${VERSION}:../../archivers/engrampa
DEPENDS+=	eom>=${VERSION}:../../graphics/eom
DEPENDS+=	libmatekbd>=${VERSION}:../../x11/libmatekbd
DEPENDS+=	libmatemixer>=${VERSION:R}.0:../../audio/libmatemixer
DEPENDS+=	libmateweather>=${VERSION}:../../misc/libmateweather
DEPENDS+=	marco>=${VERSION}:../../wm/marco
DEPENDS+=	mate-applets>=${VERSION}:../../x11/mate-applets
DEPENDS+=	mate-backgrounds>=${VERSION}:../../graphics/mate-backgrounds
DEPENDS+=	mate-calc>=${VERSION}:../../misc/mate-calc
DEPENDS+=	mate-common>=${VERSION}:../../devel/mate-common
DEPENDS+=	mate-control-center>=${VERSION}:../../x11/mate-control-center
DEPENDS+=	mate-desktop>=${VERSION}:../../x11/mate-desktop
DEPENDS+=	mate-icon-theme>=${VERSION:R}.0:../../graphics/mate-icon-theme
DEPENDS+=	mate-icon-theme-faenza>=1.20.0:../../graphics/mate-icon-theme-faenza
DEPENDS+=	mate-indicator-applet>=${VERSION:R}.0:../../x11/mate-indicator-applet
DEPENDS+=	mate-media>=${VERSION}:../../multimedia/mate-media
DEPENDS+=	mate-menus>=${VERSION}:../../x11/mate-menus
DEPENDS+=	mate-netbook>=${VERSION:R}.0:../../wm/mate-netbook
DEPENDS+=	mate-notification-daemon>=${VERSION}:../../sysutils/mate-notification-daemon
DEPENDS+=	mate-panel>=${VERSION}:../../x11/mate-panel
DEPENDS+=	mate-polkit>=${VERSION:R}.0:../../security/mate-polkit
DEPENDS+=	mate-power-manager>=${VERSION}:../../sysutils/mate-power-manager
DEPENDS+=	mate-screensaver>=${VERSION}:../../x11/mate-screensaver
DEPENDS+=	mate-sensors-applet>=${VERSION}:../../sysutils/mate-sensors-applet
DEPENDS+=	mate-session-manager>=${VERSION}:../../x11/mate-session-manager
DEPENDS+=	mate-settings-daemon>=${VERSION}:../../x11/mate-settings-daemon
#DEPENDS+=	mate-system-monitor>=1.22.2:../../sysutils/mate-system-monitor
DEPENDS+=	mate-terminal>=${VERSION}:../../x11/mate-terminal
DEPENDS+=	mate-themes>=3.22.22:../../graphics/mate-themes
#DEPENDS+=	mate-user-share>=${VERSION}:../../net/mate-user-share
DEPENDS+=	mate-utils>=${VERSION:R}.0:../../misc/mate-utils
DEPENDS+=	mozo>=${VERSION}:../../x11/mozo
DEPENDS+=	pluma>=${VERSION}:../../editors/pluma

.include "../../mk/bsd.pkg.mk"
