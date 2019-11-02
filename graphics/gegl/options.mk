# $NetBSD: options.mk,v 1.3 2019/11/02 14:05:46 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gegl
PKG_SUPPORTED_OPTIONS=	svg jasper
PKG_SUGGESTED_OPTIONS=	svg

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	svg
.if !empty(PKG_OPTIONS:Msvg)
.include "../../graphics/librsvg/buildlink3.mk"
PLIST.svg=	yes
.else
MESON_ARGS+=	-Dlibrsvg=disabled
.endif

PLIST_VARS+=	jasper
.if !empty(PKG_OPTIONS:Mjasper)
.include "../../graphics/jasper/buildlink3.mk"
PLIST.jasper=	yes
.else
MESON_ARGS+=	-Djasper=disabled
.endif
