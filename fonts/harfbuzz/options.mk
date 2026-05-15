# $NetBSD: options.mk,v 1.21 2026/05/15 17:00:57 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.harfbuzz
PKG_SUPPORTED_OPTIONS+=	introspection
PKG_SUGGESTED_OPTIONS=

PKG_SUGGESTED_OPTIONS+=	${${USE_CROSS_COMPILE:tl} == "yes":?:introspection}

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		introspection

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
TOOL_DEPENDS+=		glib2-introspection-[0-9]*:../../devel/glib2-introspection
PLIST.introspection=	yes
.else
MESON_ARGS+=	-Dintrospection=disabled
.endif
