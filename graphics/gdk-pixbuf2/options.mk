#	$NetBSD: options.mk,v 1.1 2024/04/12 19:41:39 riastradh Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.gdk-pixbuf2
PKG_SUPPORTED_OPTIONS=	introspection
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
