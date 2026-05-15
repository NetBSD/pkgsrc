#	$NetBSD: options.mk,v 1.3 2026/05/15 17:00:58 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gdk-pixbuf2
PKG_SUPPORTED_OPTIONS=	introspection tests
PKG_SUGGESTED_OPTIONS=	${${USE_CROSS_COMPILE:tl} == "yes":?:introspection}

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		introspection
.if !empty(PKG_OPTIONS:Mintrospection)
PLIST.introspection=	yes
MESON_ARGS+=		-Dintrospection=enabled
BUILDLINK_DEPMETHOD.gobject-introspection:= build
.include "../../devel/gobject-introspection/buildlink3.mk"
TOOL_DEPENDS+=		glib2-introspection-[0-9]*:../../devel/glib2-introspection
#.include "../../devel/glib2-introspection/buildlink3.mk"
.else
MESON_ARGS+=		-Dintrospection=disabled
.endif

.if !empty(PKG_OPTIONS:Mtests)
MESON_ARGS+=		-Dtests=true
MESON_ARGS+=		-Dinstalled_tests=false
.else
MESON_ARGS+=		-Dtests=false
.endif
