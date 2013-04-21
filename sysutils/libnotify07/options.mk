# $NetBSD: options.mk,v 1.1 2013/04/21 00:50:04 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libnotify07
PKG_SUPPORTED_OPTIONS=	doc introspection
PKG_SUGGESTED_OPTIONS+=	# blank
PLIST_VARS+=		doc introspection

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
.include "../../textproc/gtk-doc/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gtk-doc=yes --enable-gtk-doc-html=yes
CONFIGURE_ARGS+=	--enable-gtk-doc-pdf=yes
PLIST.doc=		yes
.else
CONFIGURE_ARGS+=	--enable-gtk-doc=no --enable-gtk-doc-html=no
CONFIGURE_ARGS+=	--enable-gtk-doc-pdf=no
.endif

.if !empty(PKG_OPTIONS:Mintrospection)
.include "../../devel/gobject-introspection/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-introspection=yes
PLIST.introspection=	yes
.else
CONFIGURE_ARGS+=	--enable-introspection=no
.endif
