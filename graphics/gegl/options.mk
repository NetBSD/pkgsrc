# $NetBSD: options.mk,v 1.4 2021/04/09 05:12:58 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gegl
PKG_SUPPORTED_OPTIONS=	svg jasper
PKG_SUGGESTED_OPTIONS=	svg

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	jasper svg

.if !empty(PKG_OPTIONS:Msvg)
.include "../../graphics/librsvg/buildlink3.mk"
PLIST.svg=	yes
.else
MESON_ARGS+=	-Dlibrsvg=disabled
.endif

.if !empty(PKG_OPTIONS:Mjasper)
.include "../../graphics/jasper/buildlink3.mk"
PLIST.jasper=	yes
.else
MESON_ARGS+=	-Djasper=disabled
.endif
