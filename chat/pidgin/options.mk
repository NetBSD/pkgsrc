# $NetBSD: options.mk,v 1.4 2008/05/17 23:45:47 tnn Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.pidgin
PKG_SUPPORTED_OPTIONS+=		dbus debug gstreamer gtkspell
PKG_SUGGESTED_OPTIONS+=		gtkspell

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		dbus

.if !empty(PKG_OPTIONS:Mdbus)
CONFIGURE_ARGS+=	--enable-dbus
PLIST.dbus=		yes
.  include "../../sysutils/dbus/buildlink3.mk"
.  include "../../sysutils/dbus-glib/buildlink3.mk"
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
