#	$NetBSD: options.mk,v 1.1 2024/04/12 19:40:41 riastradh Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.atk
PKG_SUPPORTED_OPTIONS=	introspection
PKG_SUGGESTED_OPTIONS=	${${USE_CROSS_COMPILE:tl} == "yes":?:introspection}

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		introspection
.if !empty(PKG_OPTIONS:Mintrospection)
PLIST.introspection=	yes
MESON_ARGS+=		-Dintrospection=true
BUILDLINK_DEPMETHOD.gobject-introspection:= build
.include "../../devel/gobject-introspection/buildlink3.mk"
.else
MESON_ARGS+=		-Dintrospection=false
.endif
