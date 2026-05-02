# $NetBSD: options.mk,v 1.6 2026/05/02 07:27:23 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.upower

PKG_SUPPORTED_OPTIONS+=	doc idevice introspection polkit
PKG_SUGGESTED_OPTIONS=	introspection polkit

PLIST_VARS+=		doc introspection polkit

.include "../../mk/bsd.options.mk"

##
## Build developer documentation
##
.if !empty(PKG_OPTIONS:Mdoc)
TOOL_DEPENDS+=	gtk-doc-[0-9]*:../../textproc/gtk-doc
MESON_ARGS+=	-Dgtk-doc=true
PLIST.doc=	yes
.else
MESON_ARGS+=	-Dgtk-doc=false
.endif

###
### Build GObject Introspection data
###
.if !empty(PKG_OPTIONS:Mintrospection)
BUILDLINK_DEPMETHOD.gobject-introspection+= build
.include "../../devel/gobject-introspection/buildlink3.mk"
MESON_ARGS+=    -Dintrospection=enabled
PLIST.introspection=	yes
.else
MESON_ARGS+=    -Dintrospection=disabled
.endif

###
### Enable libimobiledevice support
###
.if !empty(PKG_OPTIONS:Midevice)
.include "../../comms/libimobiledevice/buildlink3.mk"
MESON_ARGS+=    -Didevice=enabled
.else
MESON_ARGS+=    -Didevice=disabled
.endif


###
### Polkit support in UPower Daemon
###
.if !empty(PKG_OPTIONS:Mpolkit)
.  include "../../security/polkit/buildlink3.mk"
MESON_ARGS+=	-Dpolkit=enabled
PLIST.polkit=	yes
.else
MESON_ARGS+=    -Dpolkit=disabled
.endif
