# $NetBSD: options.mk,v 1.3 2020/05/31 15:47:40 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mate-polkit
PKG_SUPPORTED_OPTIONS=	introspection
PKG_SUGGESTED_OPTIONS=	# none

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mintrospection)
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.endif
