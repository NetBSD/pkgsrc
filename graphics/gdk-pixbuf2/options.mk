#	$NetBSD: options.mk,v 1.2 2024/10/26 07:35:54 nia Exp $
#

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
.else
MESON_ARGS+=		-Dintrospection=disabled
.endif

.if !empty(PKG_OPTIONS:Mtests)
MESON_ARGS+=		-Dtests=true
MESON_ARGS+=		-Dinstalled_tests=false
.else
MESON_ARGS+=		-Dtests=false
.endif
