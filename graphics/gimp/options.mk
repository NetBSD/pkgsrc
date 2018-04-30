# $NetBSD: options.mk,v 1.7 2018/04/30 05:12:51 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gimp
PKG_SUPPORTED_OPTIONS=	aalib mng pdf svg
PKG_SUGGESTED_OPTIONS=	mng svg

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		aalib mng pdf svg

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
