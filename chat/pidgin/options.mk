# $NetBSD: options.mk,v 1.13 2012/08/01 15:26:54 drochner Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.pidgin
PKG_SUPPORTED_OPTIONS+=		dbus debug gstreamer gtkspell farsight x11
PKG_SUGGESTED_OPTIONS+=		dbus gstreamer gtkspell farsight x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		dbus vv x11

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
.else
CONFIGURE_ARGS+=	--disable-vv
.endif

.if !empty(PKG_OPTIONS:Mfarsight)
CONFIGURE_ARGS+=	--enable-farstream
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
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=		yes
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif
