# $NetBSD: options.mk,v 1.18 2024/05/20 21:21:38 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.harfbuzz
PKG_SUPPORTED_OPTIONS+=	doc introspection
PKG_SUGGESTED_OPTIONS=	doc

PKG_SUGGESTED_OPTIONS+=	${${USE_CROSS_COMPILE:tl} == "yes":?:introspection}

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		doc introspection

PRINT_PLIST_AWK+=	{ if (/^share\/gtk-doc/) $$0 = "$${PLIST.doc}" $$0 }
.if !empty(PKG_OPTIONS:Mdoc)
MESON_ARGS+=		-Ddocs=enabled
TOOL_DEPENDS+=		gtk-doc>=1.32nb9:../../textproc/gtk-doc
PLIST.doc=		yes
.else
MESON_ARGS+=		-Ddocs=disabled
.endif

PRINT_PLIST_AWK+=	{ if (/^bin\/hb-info/) $$0 = "$${PLIST.introspection}" $$0 }
PRINT_PLIST_AWK+=	{ if (/^bin\/hb-ot-shape-closure/) $$0 = "$${PLIST.introspection}" $$0 }
PRINT_PLIST_AWK+=	{ if (/^bin\/hb-shape/) $$0 = "$${PLIST.introspection}" $$0 }
PRINT_PLIST_AWK+=	{ if (/^bin\/hb-subset/) $$0 = "$${PLIST.introspection}" $$0 }
PRINT_PLIST_AWK+=	{ if (/^include\/harfbuzz\/hb-glib.h/) $$0 = "$${PLIST.introspection}" $$0 }
PRINT_PLIST_AWK+=	{ if (/^include\/harfbuzz\/hb-gobject/) $$0 = "$${PLIST.introspection}" $$0 }
PRINT_PLIST_AWK+=	{ if (/^lib\/girepository/) $$0 = "$${PLIST.introspection}" $$0 }
PRINT_PLIST_AWK+=	{ if (/^lib\/libharfbuzz-gobject/) $$0 = "$${PLIST.introspection}" $$0 }
PRINT_PLIST_AWK+=	{ if (/^lib\/pkgconfig\/harfbuzz-gobject.pc/) $$0 = "$${PLIST.introspection}" $$0 }
PRINT_PLIST_AWK+=	{ if (/^share\/gir-1.0/) $$0 = "$${PLIST.introspection}" $$0 }
.if !empty(PKG_OPTIONS:Mintrospection)
MESON_ARGS+=	-Dintrospection=enabled
.include "../../devel/glib2/buildlink3.mk"
# XXX This should be TOOL_DEPENDS, no?
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
PLIST.introspection=	yes
.else
MESON_ARGS+=	-Dintrospection=disabled
.endif
