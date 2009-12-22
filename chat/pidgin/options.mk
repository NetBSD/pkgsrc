# $NetBSD: options.mk,v 1.9 2009/12/22 06:54:28 dsainty Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.pidgin
PKG_SUPPORTED_OPTIONS+=		dbus debug farsight gstreamer gtkspell
PKG_SUGGESTED_OPTIONS+=		gtkspell dbus farsight gstreamer

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		dbus vv

.if !empty(PKG_OPTIONS:Mdbus)
CONFIGURE_ARGS+=	--enable-dbus
PLIST.dbus=		yes
.  include "../../sysutils/dbus/buildlink3.mk"
.  include "../../sysutils/dbus-glib/buildlink3.mk"
.endif

# voice/video support requires both farsight and gstreamer
.if !empty(PKG_OPTIONS:Mfarsight) && !empty(PKG_OPTIONS:Mgstreamer)
CONFIGURE_ARGS+=	--enable-vv
PLIST.vv=		yes
.endif

.if !empty(PKG_OPTIONS:Mfarsight)
CONFIGURE_ARGS+=	--enable-farsight
.  include "../../multimedia/farsight2/buildlink3.mk"
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
.  include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+= --enable-debug
.endif
