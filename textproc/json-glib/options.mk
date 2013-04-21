# $NetBSD: options.mk,v 1.1 2013/04/21 14:04:20 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.json-glib
PKG_SUPPORTED_OPTIONS=	introspection nls tests
PKG_SUGGESTED_OPTIONS+=	nls tests
PLIST_VARS+=		introspection nls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mintrospection)
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

.if !empty(PKG_OPTIONS:Mtests)
TEST_TARGET=		check
.else
CONFIGURE_ARGS+=	--disable-glibtest
.endif
