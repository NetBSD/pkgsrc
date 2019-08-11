# $NetBSD: Makefile,v 1.78 2019/08/11 13:21:53 wiz Exp $

META_PACKAGE=	yes

PKGREVISION= 2
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-extras-${XFCE4_VERSION}
CATEGORIES=	meta-pkgs
COMMENT=	Xfce extras

# Applications
DEPENDS+=	ristretto-[0-9]*:../../graphics/ristretto
DEPENDS+=	xfce4-taskmanager>=1.1.0:../../sysutils/xfce4-taskmanager

# Panel Plugins
DEPENDS+=	xfce4-diskperf-plugin>=2.5.4:../../sysutils/xfce4-diskperf-plugin
DEPENDS+=	xfce4-systemload-plugin>=1.1.2:../../sysutils/xfce4-systemload-plugin
DEPENDS+=	xfce4-cpugraph-plugin>=1.0.5:../../sysutils/xfce4-cpugraph-plugin
DEPENDS+=	xfce4-wavelan-plugin>=0.5.11:../../net/xfce4-wavelan-plugin

DEPENDS+=	xfce4-battery-plugin>=1.0.5:../../sysutils/xfce4-battery-plugin
DEPENDS+=	xfce4-calculator-plugin>=0.5.2:../../misc/xfce4-calculator-plugin
DEPENDS+=	xfce4-clipman-plugin>=1.2.6:../../x11/xfce4-clipman-plugin
DEPENDS+=	xfce4-datetime-plugin>=0.6.2:../../time/xfce4-datetime-plugin
DEPENDS+=	xfce4-dict>=0.7.1:../../textproc/xfce4-dict
DEPENDS+=	xfce4-eyes-plugin>=4.4.3:../../x11/xfce4-eyes-plugin
DEPENDS+=	xfce4-fsguard-plugin>=1.0.1:../../sysutils/xfce4-fsguard-plugin
DEPENDS+=	xfce4-genmon-plugin>=3.4:../../sysutils/xfce4-genmon-plugin
DEPENDS+=	xfce4-indicator-plugin>=2.3.3:../../x11/xfce4-indicator-plugin
DEPENDS+=	xfce4-mailwatch-plugin>=1.2.0:../../mail/xfce4-mailwatch-plugin
DEPENDS+=	xfce4-mixer>=4.10.0:../../audio/xfce4-mixer
DEPENDS+=	xfce4-mount-plugin>=0.6.7:../../sysutils/xfce4-mount-plugin
DEPENDS+=	xfce4-mpc-plugin>=0.4.4:../../multimedia/xfce4-mpc-plugin
DEPENDS+=	xfce4-netload-plugin>=1.2.4:../../sysutils/xfce4-netload-plugin
DEPENDS+=	xfce4-notes-plugin>=1.7.7:../../x11/xfce4-notes-plugin
DEPENDS+=	xfce4-notifyd>=0.2.4:../../x11/xfce4-notifyd
DEPENDS+=	xfce4-places-plugin>=1.6.0:../../x11/xfce4-places-plugin
DEPENDS+=	xfce4-quicklauncher-plugin>=1.9.4:../../sysutils/xfce4-quicklauncher-plugin
DEPENDS+=	xfce4-screenshooter>=1.8.2:../../x11/xfce4-screenshooter
DEPENDS+=	xfce4-time-out-plugin>=1.0.2:../../misc/xfce4-time-out-plugin
DEPENDS+=	xfce4-timer-plugin>=1.6.0:../../time/xfce4-timer-plugin
DEPENDS+=	xfce4-verve-plugin>=1.0.1:../../sysutils/xfce4-verve-plugin
DEPENDS+=	xfce4-weather-plugin>=0.8.5:../../misc/xfce4-weather-plugin
DEPENDS+=	xfce4-xkb-plugin>=0.7.0:../../sysutils/xfce4-xkb-plugin
DEPENDS+=	xfce4-xmms-plugin>=0.5.3:../../audio/xfce4-xmms-plugin

# File Manager Plugins
DEPENDS+=	xfce4-thunar-archive-plugin>=0.3.1:../../archivers/xfce4-thunar-archive
DEPENDS+=	xfce4-thunar-media-tags-plugin>=0.2.1:../../multimedia/xfce4-thunar-media-tags
#DEPENDS+=	xfce4-thunar-vcs-plugin>=0.1.4:../../sysutils/xfce4-thunar-vcs

# Broken
# 0.2.0 fails because our thunar is too new. Fixed upstream already.
#DEPENDS+=	xfce4-thunar-shares>=0.2.0:../../sysutils/xfce4-thunar-shares

pre-extract:
	${MKDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
