# $NetBSD: Makefile,v 1.93 2019/08/11 13:21:53 wiz Exp $

META_PACKAGE=	yes

PKGREVISION= 2
.include "Makefile.common"

DISTNAME=	xfce4-${XFCE4_VERSION}
CATEGORIES=	meta-pkgs
COMMENT=	Xfce

DEPENDS+=	xfce4-tumbler>=0.1.27:../../x11/xfce4-tumbler
DEPENDS+=	xfce4-appfinder>=4.10.0:../../sysutils/xfce4-appfinder
DEPENDS+=	xfce4-desktop>=4.10.0:../../x11/xfce4-desktop
DEPENDS+=	xfce4-mousepad>=0.3.0:../../editors/xfce4-mousepad
DEPENDS+=	xfce4-panel>=4.10.0:../../x11/xfce4-panel
DEPENDS+=	xfce4-power-manager>=1.6.1:../../sysutils/xfce4-power-manager
DEPENDS+=	xfce4-orage>=4.8.4:../../time/xfce4-orage
DEPENDS+=	xfce4-settings>=4.10.0:../../x11/xfce4-settings
DEPENDS+=	xfce4-session>=4.10.0:../../x11/xfce4-session
DEPENDS+=	xfce4-terminal>=0.6.1:../../x11/xfce4-terminal
DEPENDS+=	xfce4-thunar>=1.6.0:../../sysutils/xfce4-thunar
DEPENDS+=	xfce4-wm>=4.10.0:../../wm/xfce4-wm
DEPENDS+=	xfce4-wm-themes>=4.10.0:../../wm/xfce4-wm-themes
DEPENDS+=	xfce4-xarchiver>=0.5.2:../../sysutils/xfce4-xarchiver
DEPENDS+=	elementary-xfce-icon-theme>=0.5:../../graphics/elementary-xfce-icon-theme
DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils
DEPENDS+=	gnome-themes-standard>=3.20.2:../../graphics/gnome-themes-standard

pre-extract:
	${MKDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
