# $NetBSD: Makefile,v 1.126 2020/06/02 08:22:39 adam Exp $
#

DISTNAME=	libgnome-2.32.1
PKGREVISION=	39
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnome/2.32/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Core GNOME2 library (non-graphical)
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

PKGCONFIG_OVERRIDE=	libgnome/libgnome-2.0.pc.in

CONFIGURE_ARGS=		--enable-gtk-doc=no
CONFIGURE_ARGS+=	--disable-esd
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR:Q}
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS}
INSTALL_MAKE_FLAGS+=	soundlistdir=${PREFIX}/share/examples/libgnome/sound/events

BUILD_DEFS+=	VARBASE

OWN_DIRS=	${PKG_SYSCONFDIR}/sound/events

EGDIR=		${PREFIX}/share/examples/libgnome
CONF_FILES=	${EGDIR}/sound/events/gnome-2.soundlist \
		${PKG_SYSCONFDIR}/sound/events/gnome-2.soundlist
CONF_FILES+=	${EGDIR}/sound/events/gtk-events-2.soundlist \
		${PKG_SYSCONFDIR}/sound/events/gtk-events-2.soundlist

GCONF_SCHEMAS=	desktop_gnome_accessibility_keyboard.schemas
GCONF_SCHEMAS+=	desktop_gnome_accessibility_startup.schemas
GCONF_SCHEMAS+=	desktop_gnome_applications_browser.schemas
GCONF_SCHEMAS+=	desktop_gnome_applications_terminal.schemas
GCONF_SCHEMAS+=	desktop_gnome_applications_window_manager.schemas
GCONF_SCHEMAS+=	desktop_gnome_background.schemas
GCONF_SCHEMAS+=	desktop_gnome_file_views.schemas
GCONF_SCHEMAS+=	desktop_gnome_interface.schemas
GCONF_SCHEMAS+=	desktop_gnome_lockdown.schemas
GCONF_SCHEMAS+=	desktop_gnome_peripherals_keyboard.schemas
GCONF_SCHEMAS+=	desktop_gnome_peripherals_mouse.schemas
GCONF_SCHEMAS+=	desktop_gnome_sound.schemas
GCONF_SCHEMAS+=	desktop_gnome_thumbnail_cache.schemas
GCONF_SCHEMAS+=	desktop_gnome_thumbnailers.schemas
GCONF_SCHEMAS+=	desktop_gnome_typing_break.schemas
GCONF_SCHEMAS+=	desktop_gnome_applications_at_mobility.schemas
GCONF_SCHEMAS+=	desktop_gnome_applications_at_visual.schemas
GCONF_SCHEMAS+=	desktop_gnome_applications_office.schemas

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.8.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
BUILDLINK_API_DEPENDS.libbonobo+=	libbonobo>=2.13.0
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
