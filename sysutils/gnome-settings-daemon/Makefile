# $NetBSD: Makefile,v 1.51 2014/05/05 00:48:20 ryoon Exp $
#

DISTNAME=	gnome-settings-daemon-2.32.1
PKGREVISION=	28
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-settings-daemon/2.32/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME settings daemon

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake msgfmt

CONFLICTS+=	gnome-control-center<2.22.0

GCONF_SCHEMAS+=	gnome-settings-daemon.schemas
GCONF_SCHEMAS+=	desktop_gnome_font_rendering.schemas
GCONF_SCHEMAS+=	desktop_gnome_keybindings.schemas
GCONF_SCHEMAS+=	apps_gnome_settings_daemon_keybindings.schemas
GCONF_SCHEMAS+=	apps_gnome_settings_daemon_xrandr.schemas
GCONF_SCHEMAS+=	apps_gnome_settings_daemon_housekeeping.schemas
GCONF_SCHEMAS+=	desktop_gnome_peripherals_touchpad.schemas
GCONF_SCHEMAS+=	desktop_gnome_peripherals_smartcard.schemas
PKGCONFIG_OVERRIDE+=	data/gnome-settings-daemon.pc.in

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome-settings-daemon
PKG_SUPPORTED_OPTIONS=	pulseaudio
.include "../../mk/bsd.options.mk"
PLIST_VARS+=		pulseaudio

.if !empty(PKG_OPTIONS:Mpulseaudio)
PLIST.pulseaudio=	yes
BUILDLINK_API_DEPENDS.pulseaudio+=	pulseaudio>=0.9.15
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.endif
.include "../../devel/GConf/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.74
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.21.2
.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgnomekbd+=	libgnomekbd>=2.31.2
.include "../../x11/libgnomekbd/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxklavier+=	libxklavier>=5.0
.include "../../x11/libxklavier/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
