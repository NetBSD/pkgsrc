# $NetBSD: Makefile,v 1.119.2.1 2012/10/03 12:08:42 spz Exp $
#

DISTNAME=		gnome-utils-2.32.0
PKGREVISION=		16
CATEGORIES=		misc gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-utils/2.32/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Set of useful GNOME2 utilities and applications

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=	gnome-dictionary/libgdict/gdict-1.0.pc.in
PKGCONFIG_OVERRIDE+=	gnome-dictionary/libgdict/gdict-1.0-uninstalled.pc.in

CONFIGURE_ARGS+=	--enable-gtk-doc=no

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome-utils
PKG_SUPPORTED_OPTIONS+=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

GCONF_SCHEMAS+=	baobab.schemas
GCONF_SCHEMAS+=	gnome-dictionary.schemas
GCONF_SCHEMAS+=	gnome-screenshot.schemas
GCONF_SCHEMAS+=	gnome-search-tool.schemas
GCONF_SCHEMAS+=	gnome-system-log.schemas

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.9.1
BUILDLINK_API_DEPENDS.gnome-panel+=	gnome-panel>=2.13.4
BUILDLINK_API_DEPENDS.gnome-vfs+=	gnome-vfs>=2.8.4
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.8.0
BUILDLINK_API_DEPENDS.libgnome+=	libgnome>=2.13.2
BUILDLINK_API_DEPENDS.libgnomecanvas+=	libgnomecanvas>=2.10.2
BUILDLINK_API_DEPENDS.libgnomeui+=	libgnomeui>=2.13.7

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/GConf/schemas.mk"
.include "../../devel/GConf-ui/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
