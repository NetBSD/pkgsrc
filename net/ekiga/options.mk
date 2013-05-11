# $NetBSD: options.mk,v 1.2 2013/05/11 20:11:38 riastradh Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ekiga
PKG_SUPPORTED_OPTIONS+= avahi dbus evolution-data-server gconf gnome notify
PKG_SUGGESTED_OPTIONS+= avahi dbus evolution-data-server gconf gnome notify

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		dbus gconf not-gconf

.if !empty(PKG_OPTIONS:Mavahi)
.include "../../net/avahi/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif

.if !empty(PKG_OPTIONS:Mdbus)
CONFIGURE_ARGS+=	--enable-dbus --enable-dbus-service
PLIST.dbus=		yes
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-dbus --disable-dbus-service
.endif

.if !empty(PKG_OPTIONS:Mevolution-data-server)
CONFIGURE_ARGS+=	--enable-eds
.include "../../mail/evolution-data-server/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-eds
.endif

.if !empty(PKG_OPTIONS:Mgconf)
PLIST.gconf=		yes
GCONF_SCHEMAS=		ekiga.schemas
CONFIGURE_ARGS+=	--enable-gconf
.include "../../devel/GConf/schemas.mk"
.else
PLIST.not-gconf=	yes
CONFIGURE_ARGS+=	--disable-gconf
.endif

.if !empty(PKG_OPTIONS:Mgnome)
CONFIGURE_ARGS+=	--enable-gnome
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gnome
.endif

.if !empty(PKG_OPTIONS:Mnotify)
CONFIGURE_ARGS+=	--enable-notify
.include "../../sysutils/libnotify/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-notify
.endif
