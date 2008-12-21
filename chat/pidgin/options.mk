# $NetBSD: options.mk,v 1.5 2008/12/21 00:12:10 ahoka Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.pidgin
PKG_SUPPORTED_OPTIONS+=		dbus debug gstreamer gtkspell avahi
PKG_SUGGESTED_OPTIONS+=		gtkspell dbus gstreamer avahi

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		dbus

.if !empty(PKG_OPTIONS:Mdbus)
CONFIGURE_ARGS+=	--enable-dbus
PLIST.dbus=		yes
.  include "../../sysutils/dbus/buildlink3.mk"
.  include "../../sysutils/dbus-glib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mavahi)
PLIST.avahi=		yes
.  include "../../net/avahi/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgtkspell)
CONFIGURE_ARGS+=	--enable-gtkspell
.  include "../../textproc/gtkspell/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gtkspell
.endif

.if !empty(PKG_OPTIONS:Mgstreamer)
CONFIGURE_ARGS+=	--enable-gstreamer
.  include "../../multimedia/gstreamer0.10/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+= --enable-debug
.endif
