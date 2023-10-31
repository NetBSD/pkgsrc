# $NetBSD: Makefile,v 1.48 2023/10/31 00:38:07 gutteridge Exp $

PKGNAME=	mate-${VERSION}
PKGREVISION=	2
CATEGORIES=	meta-pkgs

COMMENT=	Meta-package for MATE desktop environment

META_PACKAGE=	yes

.include "../../meta-pkgs/mate/Makefile.common"

DEPENDS+=	atril>=${VERSION}:../../print/atril
DEPENDS+=	caja>=${VERSION:R}.3:../../sysutils/caja
DEPENDS+=	caja-dropbox>=${VERSION:R}.0:../../sysutils/caja-dropbox
DEPENDS+=	caja-extensions>=${VERSION}:../../sysutils/caja-extensions
DEPENDS+=	engrampa>=${VERSION}:../../archivers/engrampa
DEPENDS+=	eom>=${VERSION}:../../graphics/eom
DEPENDS+=	libmatekbd>=${VERSION}:../../x11/libmatekbd
DEPENDS+=	libmatemixer>=${VERSION}:../../audio/libmatemixer
DEPENDS+=	libmateweather>=${VERSION:R}.2:../../misc/libmateweather
DEPENDS+=	marco>=${VERSION:R}.2:../../wm/marco
DEPENDS+=	mate-applets>=${VERSION}:../../x11/mate-applets
DEPENDS+=	mate-backgrounds>=${VERSION:R}.0:../../graphics/mate-backgrounds
DEPENDS+=	mate-calc>=${VERSION:R}.0:../../misc/mate-calc
DEPENDS+=	mate-common>=${VERSION:R}.0:../../devel/mate-common
DEPENDS+=	mate-control-center>=${VERSION}:../../x11/mate-control-center
DEPENDS+=	mate-desktop>=${VERSION:R}.2:../../x11/mate-desktop
DEPENDS+=	mate-icon-theme>=${VERSION:R}.0:../../graphics/mate-icon-theme
DEPENDS+=	mate-icon-theme-faenza>=1.20.0:../../graphics/mate-icon-theme-faenza
DEPENDS+=	mate-indicator-applet>=${VERSION:R}.0:../../x11/mate-indicator-applet
DEPENDS+=	mate-media>=${VERSION}:../../multimedia/mate-media
DEPENDS+=	mate-menus>=${VERSION}:../../x11/mate-menus
DEPENDS+=	mate-netbook>=${VERSION:R}.0:../../wm/mate-netbook
DEPENDS+=	mate-notification-daemon>=${VERSION}:../../sysutils/mate-notification-daemon
DEPENDS+=	mate-panel>=${VERSION:R}.3:../../x11/mate-panel
DEPENDS+=	mate-polkit>=${VERSION}:../../security/mate-polkit
DEPENDS+=	mate-power-manager>=${VERSION}:../../sysutils/mate-power-manager
DEPENDS+=	mate-screensaver>=${VERSION:R}.2:../../x11/mate-screensaver
DEPENDS+=	mate-sensors-applet>=${VERSION:R}.0:../../sysutils/mate-sensors-applet
DEPENDS+=	mate-session-manager>=${VERSION}:../../x11/mate-session-manager
DEPENDS+=	mate-settings-daemon>=${VERSION}:../../x11/mate-settings-daemon
#DEPENDS+=	mate-system-monitor>=1.22.2:../../sysutils/mate-system-monitor
DEPENDS+=	mate-terminal>=${VERSION}:../../x11/mate-terminal
DEPENDS+=	mate-themes>=3.22.24:../../graphics/mate-themes
#DEPENDS+=	mate-user-share>=${VERSION:R}.0:../../net/mate-user-share
DEPENDS+=	mate-utils>=${VERSION}:../../misc/mate-utils
DEPENDS+=	mozo>=${VERSION:R}.2:../../x11/mozo
DEPENDS+=	pluma>=${VERSION:R}.1:../../editors/pluma

.include "../../mk/bsd.pkg.mk"
