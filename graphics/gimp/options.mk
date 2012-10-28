# $NetBSD: options.mk,v 1.5 2012/10/28 23:40:24 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gimp
PKG_SUPPORTED_OPTIONS=	aalib mng svg
PKG_SUGGESTED_OPTIONS=	mng svg

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		aalib mng svg

.if !empty(PKG_OPTIONS:Maalib)
.include "../../graphics/aalib/buildlink3.mk"
PLIST.aalib=		yes
.endif

.if !empty(PKG_OPTIONS:Mmng)
.include "../../graphics/mng/buildlink3.mk"
PLIST.mng=		yes
.endif

.if !empty(PKG_OPTIONS:Msvg)
.include "../../graphics/librsvg/buildlink3.mk"
PLIST.svg=		yes
.endif
