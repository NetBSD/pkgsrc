# $NetBSD: options.mk,v 1.1 2015/08/25 13:23:02 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gegl
PKG_SUPPORTED_OPTIONS=	svg
PKG_SUGGESTED_OPTIONS=	svg

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	svg

.if !empty(PKG_OPTIONS:Msvg)
.include "../../graphics/librsvg/buildlink3.mk"
PLIST.svg=	yes
.endif
