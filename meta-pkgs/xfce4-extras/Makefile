# $NetBSD: Makefile,v 1.123 2024/05/30 03:33:28 gutteridge Exp $

META_PACKAGE=	yes

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-extras-${XFCE4_VERSION}
PKGREVISION=	20
CATEGORIES=	meta-pkgs
COMMENT=	Meta-package for extra optional items for the Xfce desktop environment

# Applications
DEPENDS+=	ristretto>=0.13.2:../../graphics/ristretto
DEPENDS+=	xfce4-taskmanager>=1.5.7:../../sysutils/xfce4-taskmanager

# Panel Plugins
DEPENDS+=	xfce4-diskperf-plugin>=2.7.0:../../sysutils/xfce4-diskperf-plugin
DEPENDS+=	xfce4-systemload-plugin>=1.3.2:../../sysutils/xfce4-systemload-plugin
DEPENDS+=	xfce4-cpugraph-plugin>=1.2.10:../../sysutils/xfce4-cpugraph-plugin
DEPENDS+=	xfce4-wavelan-plugin>=0.6.3:../../net/xfce4-wavelan-plugin
DEPENDS+=	xfce4-battery-plugin>=1.1.5:../../sysutils/xfce4-battery-plugin
DEPENDS+=	xfce4-calculator-plugin>=0.7.0:../../misc/xfce4-calculator-plugin
DEPENDS+=	xfce4-clipman-plugin>=1.6.6:../../x11/xfce4-clipman-plugin
DEPENDS+=	xfce4-dict>=0.8.6:../../textproc/xfce4-dict
DEPENDS+=	xfce4-eyes-plugin>=4.6.0:../../x11/xfce4-eyes-plugin
DEPENDS+=	xfce4-fsguard-plugin>=1.1.3:../../sysutils/xfce4-fsguard-plugin
DEPENDS+=	xfce4-genmon-plugin>=4.1.1:../../sysutils/xfce4-genmon-plugin
DEPENDS+=	xfce4-indicator-plugin>=2.4.2:../../x11/xfce4-indicator-plugin
DEPENDS+=	xfce4-mailwatch-plugin>=1.3.1:../../mail/xfce4-mailwatch-plugin
DEPENDS+=	xfce4-mount-plugin>=1.1.6:../../sysutils/xfce4-mount-plugin
DEPENDS+=	xfce4-mpc-plugin>=0.5.3:../../multimedia/xfce4-mpc-plugin
DEPENDS+=	xfce4-netload-plugin>=1.4.1:../../sysutils/xfce4-netload-plugin
DEPENDS+=	xfce4-notes-plugin>=1.11.0:../../x11/xfce4-notes-plugin
DEPENDS+=	xfce4-notifyd>=0.9.4:../../x11/xfce4-notifyd
DEPENDS+=	xfce4-places-plugin>=1.8.3:../../x11/xfce4-places-plugin
DEPENDS+=	xfce4-screenshooter>=1.10.6:../../x11/xfce4-screenshooter
DEPENDS+=	xfce4-smartbookmark-plugin>=0.5.2:../../misc/xfce4-smartbookmark-plugin
DEPENDS+=	xfce4-time-out-plugin>=1.1.3:../../misc/xfce4-time-out-plugin
DEPENDS+=	xfce4-timer-plugin>=1.7.2:../../time/xfce4-timer-plugin
DEPENDS+=	xfce4-verve-plugin>=2.0.3:../../sysutils/xfce4-verve-plugin
DEPENDS+=	xfce4-weather-plugin>=0.11.2:../../misc/xfce4-weather-plugin
DEPENDS+=	xfce4-whiskermenu-plugin>=2.8.3:../../x11/xfce4-whiskermenu-plugin
DEPENDS+=	xfce4-xkb-plugin>=0.8.3:../../sysutils/xfce4-xkb-plugin
DEPENDS+=	xfce4-docklike-plugin>=0.4.2:../../x11/xfce4-docklike-plugin

# File Manager Plugins
DEPENDS+=	xfce4-thunar-archive-plugin>=0.5.2:../../archivers/xfce4-thunar-archive
DEPENDS+=	xfce4-thunar-media-tags-plugin>=0.2.1:../../multimedia/xfce4-thunar-media-tags
#DEPENDS+=	xfce4-thunar-vcs-plugin>=0.1.4:../../sysutils/xfce4-thunar-vcs

# Broken
# 0.2.0 fails because our thunar is too new. Fixed upstream already.
#DEPENDS+=	xfce4-thunar-shares>=0.2.0:../../sysutils/xfce4-thunar-shares

pre-extract:
	${MKDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
