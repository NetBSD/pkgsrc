# $NetBSD: options.mk,v 1.2 2019/07/16 15:34:25 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gegl
PKG_SUPPORTED_OPTIONS=	svg jasper
PKG_SUGGESTED_OPTIONS=	svg

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	svg
.if !empty(PKG_OPTIONS:Msvg)
.include "../../graphics/librsvg/buildlink3.mk"
PLIST.svg=	yes
.endif

PLIST_VARS+=	jasper
.if !empty(PKG_OPTIONS:Mjasper)
.include "../../graphics/jasper/buildlink3.mk"
PLIST.jasper=	yes
.else
CONFIGURE_ARGS+=	--without-jasper
.endif
