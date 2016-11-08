# $NetBSD: options.mk,v 1.3 2016/11/08 10:24:43 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libnotify
PKG_SUPPORTED_OPTIONS=	doc introspection
PKG_SUGGESTED_OPTIONS+=	introspection
PLIST_VARS+=		doc introspection

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
CONFIGURE_ARGS+=	--enable-docbook-docs
PLIST.doc=		yes
.else
CONFIGURE_ARGS+=	--disable-docbook-docs
.endif

.if !empty(PKG_OPTIONS:Mintrospection)
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=0.9.12
.include "../../devel/gobject-introspection/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-introspection=yes
PLIST.introspection=	yes
.else
CONFIGURE_ARGS+=	--enable-introspection=no
.endif
