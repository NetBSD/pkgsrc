# $NetBSD: Makefile,v 1.152 2025/01/28 01:21:55 gutteridge Exp $

META_PACKAGE=	yes

.include "Makefile.common"

DISTNAME=	xfce4-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	meta-pkgs
COMMENT=	Meta-package for the Xfce desktop environment

DEPENDS+=	xfce4-tumbler>=4.20.0:../../x11/xfce4-tumbler
DEPENDS+=	xfce4-appfinder>=4.20.0:../../sysutils/xfce4-appfinder
DEPENDS+=	xfce4-desktop>=4.20.0nb1:../../x11/xfce4-desktop
DEPENDS+=	xfce4-mousepad>=0.6.3:../../editors/xfce4-mousepad
DEPENDS+=	xfce4-panel>=4.20.0:../../x11/xfce4-panel
DEPENDS+=	xfce4-power-manager>=4.20.0:../../sysutils/xfce4-power-manager
DEPENDS+=	xfce4-settings>=4.20.0:../../x11/xfce4-settings
DEPENDS+=	xfce4-session>=4.20.0:../../x11/xfce4-session
DEPENDS+=	xfce4-terminal>=1.1.4:../../x11/xfce4-terminal
DEPENDS+=	xfce4-thunar>=4.20.1:../../sysutils/xfce4-thunar
DEPENDS+=	xfce4-wm>=4.20.0:../../wm/xfce4-wm
DEPENDS+=	xfce4-wm-themes>=4.10.0:../../wm/xfce4-wm-themes
DEPENDS+=	elementary-xfce-icon-theme>=0.20:../../graphics/elementary-xfce-icon-theme
DEPENDS+=	gnome-themes-standard>=3.20.2:../../graphics/gnome-themes-standard
DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils

pre-extract:
	${MKDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
