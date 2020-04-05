# $NetBSD: Makefile,v 1.30 2020/04/05 16:05:39 bsiegert Exp $

PKGNAME=	mate-${VERSION}
CATEGORIES=	meta-pkgs

COMMENT=	Meta-package for MATE desktop environment

META_PACKAGE=	yes

.include "../../meta-pkgs/mate/Makefile.common"

DEPENDS+=	atril>=${VERSION}:../../print/atril
DEPENDS+=	caja>=${VERSION}:../../sysutils/caja
DEPENDS+=	caja-dropbox>=${VERSION:R}.1:../../sysutils/caja-dropbox
DEPENDS+=	caja-extensions>=${VERSION:R}.1:../../sysutils/caja-extensions
DEPENDS+=	engrampa>=${VERSION}:../../archivers/engrampa
DEPENDS+=	eom>=${VERSION}:../../graphics/eom
DEPENDS+=	libmatekbd>=${VERSION:R}.0:../../x11/libmatekbd
DEPENDS+=	libmatemixer>=${VERSION:R}.0:../../audio/libmatemixer
DEPENDS+=	libmateweather>=${VERSION:R}.1:../../misc/libmateweather
DEPENDS+=	marco>=${VERSION}:../../wm/marco
DEPENDS+=	mate-applets>=${VERSION}:../../x11/mate-applets
DEPENDS+=	mate-backgrounds>=${VERSION:R}.0:../../graphics/mate-backgrounds
DEPENDS+=	mate-calc>=${VERSION}:../../misc/mate-calc
DEPENDS+=	mate-common>=${VERSION}:../../devel/mate-common
DEPENDS+=	mate-control-center>=${VERSION}:../../x11/mate-control-center
DEPENDS+=	mate-desktop>=${VERSION}:../../x11/mate-desktop
DEPENDS+=	mate-icon-theme>=${VERSION}:../../graphics/mate-icon-theme
DEPENDS+=	mate-icon-theme-faenza>=1.20.0:../../graphics/mate-icon-theme-faenza
DEPENDS+=	mate-indicator-applet>=${VERSION:R}.1:../../x11/mate-indicator-applet
DEPENDS+=	mate-media>=${VERSION}:../../multimedia/mate-media
DEPENDS+=	mate-menus>=${VERSION:R}.1:../../x11/mate-menus
DEPENDS+=	mate-netbook>=${VERSION}:../../wm/mate-netbook
DEPENDS+=	mate-notification-daemon>=${VERSION:R}.1:../../sysutils/mate-notification-daemon
DEPENDS+=	mate-panel>=${VERSION}:../../x11/mate-panel
DEPENDS+=	mate-polkit>=${VERSION:R}.0:../../security/mate-polkit
DEPENDS+=	mate-power-manager>=${VERSION}:../../sysutils/mate-power-manager
DEPENDS+=	mate-screensaver>=${VERSION}:../../x11/mate-screensaver
DEPENDS+=	mate-sensors-applet>=${VERSION:R}.1:../../sysutils/mate-sensors-applet
DEPENDS+=	mate-session-manager>=${VERSION}:../../x11/mate-session-manager
DEPENDS+=	mate-settings-daemon>=${VERSION:R}.1:../../x11/mate-settings-daemon
#DEPENDS+=	mate-system-monitor>=${VERSION}:../../sysutils/mate-system-monitor
DEPENDS+=	mate-terminal>=${VERSION:R}.1:../../x11/mate-terminal
DEPENDS+=	mate-themes>=3.22.20:../../graphics/mate-themes
#DEPENDS+=	mate-user-share>=${VERSION:R}.1:../../net/mate-user-share
DEPENDS+=	mate-utils>=${VERSION}:../../misc/mate-utils
DEPENDS+=	mozo>=${VERSION}:../../x11/mozo
DEPENDS+=	pluma>=${VERSION}:../../editors/pluma

.include "../../mk/bsd.pkg.mk"
