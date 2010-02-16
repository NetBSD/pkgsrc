# $NetBSD: Makefile,v 1.17 2010/02/16 13:35:40 wiz Exp $
#

DISTNAME=	gnome-settings-daemon-2.28.1
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-settings-daemon/2.28/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME settings daemon

PKG_DESTDIR_SUPPORT=	user-destdir

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
PKGCONFIG_OVERRIDE+=	data/gnome-settings-daemon.pc.in

BUILDLINK_API_DEPENDS.libxklavier+=	libxklavier>=3.3

# pkgsrc pulseaudio is too old
#.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libgnomekbd/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
