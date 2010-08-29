# $NetBSD: Makefile,v 1.79 2010/08/29 09:28:01 obache Exp $
#

DISTNAME=	libgnome-2.30.0
PKGREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnome/2.30/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Core GNOME2 library (non-graphical)

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_API_DEPENDS.esound+=	esound>=0.2.26

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

PKGCONFIG_OVERRIDE=	libgnome/libgnome-2.0.pc.in

CONFIGURE_ARGS=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR:Q}
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS}
INSTALL_MAKE_FLAGS+=	soundlistdir=${PREFIX}/share/examples/libgnome/sound/events

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

PKG_OPTIONS_VAR= PKG_OPTIONS.libgnome
PKG_SUPPORTED_OPTIONS= esound
.include "../../mk/bsd.options.mk"
.if !empty(PKG_OPTIONS:Mesound)
.include "../../audio/esound/buildlink3.mk"
BUILDLINK_API_DEPENDS.audiofile+=	libaudiofile>=0.2.3
.include "../../audio/libaudiofile/buildlink3.mk"
.else
CONFIGURE_ARGS+= --disable-esd
.endif

BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.8.0
BUILDLINK_API_DEPENDS.libbonobo+=	libbonobo>=2.13.0

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
