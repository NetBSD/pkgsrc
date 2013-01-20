# $NetBSD: options.mk,v 1.6 2013/01/20 00:52:18 riastradh Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.evince
PKG_SUPPORTED_OPTIONS=	dbus dvi djvu gconf gdk-pixbuf gnome-keyring
PKG_SUPPORTED_OPTIONS+=	scrollkeeper

PKG_SUGGESTED_OPTIONS+=	dbus gconf gnome-keyring scrollkeeper

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

.if !empty(PKG_OPTIONS:Mdbus)
.include "../../sysutils/dbus/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.70
.include "../../sysutils/dbus-glib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-dbus
PLIST.dbus=		yes
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

.if !empty(PKG_OPTIONS:Mdvi)
CONFIGURE_ARGS+=	--enable-dvi
PLIST.dvi=		yes
GCONF_SCHEMAS+=	evince-thumbnailer-dvi.schemas
.include "../../print/kpathsea/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdjvu)
CONFIGURE_ARGS+=	--enable-djvu
PLIST.djvu=		yes
GCONF_SCHEMAS+=	evince-thumbnailer-djvu.schemas
.include "../../graphics/djvulibre-lib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgconf)
.include "../../devel/GConf/schemas.mk"
CONFIGURE_ARGS+=	--with-gconf
GCONF_SCHEMAS+=		evince-thumbnailer.schemas
GCONF_SCHEMAS+=		evince-thumbnailer-ps.schemas
GCONF_SCHEMAS+=		evince-thumbnailer-comics.schemas
PLIST.gconf=		yes
.else
CONFIGURE_ARGS+=	--without-gconf
CONFIGURE_ARGS+=	--disable-schemas-install
.endif

.if !empty(PKG_OPTIONS:Mgdk-pixbuf)
CONFIGURE_ARGS+=	--enable-pixbuf
PLIST.gdk-pixbuf=	yes
.endif

.if !empty(PKG_OPTIONS:Mgnome-keyring)
.include "../../security/libgnome-keyring/buildlink3.mk"
CONFIGURE_ARGS+=	--with-keyring
.else
CONFIGURE_ARGS+=	--without-keyring
.endif

.if !empty(PKG_OPTIONS:Mscrollkeeper)
.include "../../mk/omf-scrollkeeper.mk"
CONFIGURE_ARGS+=	--enable-scrollkeeper
.else
CONFIGURE_ARGS+=	--disable-scrollkeeper
.endif
