# $NetBSD: options.mk,v 1.2 2026/05/07 17:52:39 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gcr4

PKG_OPTIONS_OPTIONAL_GROUPS=	crypto
PKG_OPTIONS_GROUP.crypto=	libgcrypt gnutls

PKG_SUPPORTED_OPTIONS=	doc gtk4 introspection vapi
PKG_SUGGESTED_OPTIONS+=	introspection vapi libgcrypt

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		doc gtk4 introspection vapi

#
# Build documentation
#
.if !empty(PKG_OPTIONS:Mdoc)
.  include "../../devel/py-gi-docgen/buildlink3.mk"
PYTHON_FOR_BUILD_ONLY=	tool
MESON_ARGS+=	-Dgtk_doc=true
PLIST.doc=	yes
.else
MESON_ARGS+=	-Dgtk_doc=false
.endif

#
# Enable the GTK4 library frontend
#
.if !empty(PKG_OPTIONS:Mgtk4)
MESON_ARGS+=    -Dgtk4=true
.  include "../../graphics/hicolor-icon-theme/buildlink3.mk"
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
# Backend library for transport encryption
#
.if !empty(PKG_OPTIONS:Mlibgcrypt)
MESON_ARGS+=    -Dcrypto=libgcrypt
.  include "../../security/libgcrypt/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mgnutls)
.  include "../../security/gnutls/buildlink3.mk"
MESON_ARGS+=    -Dcrypto=gnutls
.endif

#
# Generate Vala API bindings
#
.if !empty(PKG_OPTIONS:Mvapi)
MESON_ARGS+=    -Dvapi=true
.  include "../../lang/vala/buildlink3.mk"
PLIST.vapi=             yes
.else
MESON_ARGS+=    -Dvapi=false
.endif
