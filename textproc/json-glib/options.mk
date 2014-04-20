# $NetBSD: options.mk,v 1.4 2014/04/20 09:32:57 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.json-glib
PKG_SUPPORTED_OPTIONS=	introspection nls
PKG_SUGGESTED_OPTIONS+=	introspection nls
PLIST_VARS+=		introspection nls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mintrospection)
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=0.9.5
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-introspection=yes
PLIST.introspection=	yes
.else
CONFIGURE_ARGS+=	--enable-introspection=no
.endif

.if !empty(PKG_OPTIONS:Mnls)
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
PLIST.nls=		yes
.else
CONFIGURE_ARGS+=	--disable-nls
.endif
