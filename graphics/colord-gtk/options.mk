# $NetBSD: options.mk,v 1.1 2026/04/26 16:55:31 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.colord-gtk

PKG_OPTIONS_REQUIRED_GROUPS=	gtk
PKG_OPTIONS_GROUP.gtk=		gtk3 gtk4

PKG_SUPPORTED_OPTIONS=	doc gtk3 gtk4 introspection vapi
PKG_SUGGESTED_OPTIONS+=	gtk3 introspection vapi

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

#
# Build documentation
#
.if !empty(PKG_OPTIONS:Mdoc)
TOOL_DEPENDS+=	gtk-doc-[0-9]*:../../textproc/gtk-doc
MESON_ARGS+=	-Ddocs=true
PLIST.doc=	yes
.else
MESON_ARGS+=	-Ddocs=false
.endif

#
# Enable Gtk3 frontend
#
.if !empty(PKG_OPTIONS:Mgtk3)
MESON_ARGS+=	-Dgtk3=true
.  include "../../x11/gtk3/buildlink3.mk"
PKGCONFIG_OVERRIDE+=	output/meson-private/colord-gtk.pc
PLIST.gtk3=	yes
.else
MESON_ARGS+=	-Dgtk3=false
.endif

#
# Enable Gtk4 frontend
#
.if !empty(PKG_OPTIONS:Mgtk4)
MESON_ARGS+=    -Dgtk4=true
.  include "../../x11/gtk4/buildlink3.mk"
PKGCONFIG_OVERRIDE+=	output/meson-private/colord-gtk4.pc
PLIST.gtk4=   yes
.else
MESON_ARGS+=    -Dgtk4=false
.endif

#
# Build GObject Introspection data
#
.if !empty(PKG_OPTIONS:Mintrospection)
MESON_ARGS+=    -Dintrospection=true
.  include "../../devel/gobject-introspection/buildlink3.mk"
PLIST.introspection=    yes
.else
MESON_ARGS+=    -Dintrospection=false
.endif

#
# Generate Vala bindings
#
.if !empty(PKG_OPTIONS:Mvapi)
MESON_ARGS+=    -Dvapi=true
.  include "../../lang/vala/buildlink3.mk"
PLIST.vapi=             yes
.else
MESON_ARGS+=    -Dvapi=false
.endif
