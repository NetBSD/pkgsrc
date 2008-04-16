# $NetBSD: Makefile,v 1.2 2008/04/16 18:11:26 drochner Exp $
#

DISTNAME=	gnome-settings-daemon-2.22.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-settings-daemon/2.22/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME settings daemon

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake

CONFLICTS+=	gnome-control-center<2.22.0

GCONF_SCHEMAS+=	gnome-settings-daemon.schemas
GCONF_SCHEMAS+=	desktop_gnome_font_rendering.schemas
GCONF_SCHEMAS+=	apps_gnome_settings_daemon_keybindings.schemas
GCONF_SCHEMAS+=	apps_gnome_settings_daemon_screensaver.schemas
PKGCONFIG_OVERRIDE+=	data/gnome-settings-daemon.pc.in

BUILDLINK_API_DEPENDS.libxklavier+=	libxklavier>=3.3

.include "../../devel/GConf/schemas.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/libgnomekbd/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
