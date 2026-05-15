# $NetBSD: options.mk,v 1.2 2026/05/15 17:00:58 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.colord
PKG_SUPPORTED_OPTIONS=	doc introspection sane udev vapi
PKG_SUGGESTED_OPTIONS=	introspection vapi

# check for a working libudev implementation
.include "../../mk/udev.buildlink3.mk"
.if ${UDEV_TYPE} != "none"
PKG_SUGGESTED_OPTIONS+=  udev
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		doc introspection sane udev vapi

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
# Build GObject Introspection data
#
.if !empty(PKG_OPTIONS:Mintrospection)
MESON_ARGS+=	-Dintrospection=true
TOOL_DEPENDS+=	glib2-introspection-[0-9]*:../../devel/glib2-introspection
.  include "../../devel/gobject-introspection/buildlink3.mk"
PLIST.introspection=	yes
.else
MESON_ARGS+=	-Dintrospection=false
.endif

#
# Enable SANE support
#
.if !empty(PKG_OPTIONS:Msane)
.  include "../../graphics/sane-backends/buildlink3.mk"
MESON_ARGS+=    -Dsane=true
PLIST.sane=             yes
.else
MESON_ARGS+=    -Dsane=false
.endif

#
# Generate Vala API file
#
.if !empty(PKG_OPTIONS:Mvapi)
MESON_ARGS+=    -Dvapi=true
.  include "../../lang/vala/buildlink3.mk"
PLIST.vapi=             yes
.else
MESON_ARGS+=    -Dvapi=false
.endif

#
# Libudev support
#
.if !empty(PKG_OPTIONS:Mudev)
.  include "../../devel/libgudev/buildlink3.mk"
MESON_ARGS+=    -Dudev=true
PLIST_VARS+=    udev
PLIST.udev=     yes
.else
MESON_ARGS+=    -Dudev=false
.endif
