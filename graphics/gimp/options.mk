# $NetBSD: options.mk,v 1.3 2008/04/12 22:43:01 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gimp
PKG_SUPPORTED_OPTIONS=	aalib gnome mng svg
PKG_SUGGESTED_OPTIONS=	aalib gnome mng svg

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		aalib gnome mng svg

.if !empty(PKG_OPTIONS:Maalib)
.include "../../graphics/aalib/buildlink3.mk"
PLIST.aalib=		yes
.endif

.if !empty(PKG_OPTIONS:Mgnome)
.include "../../www/libgtkhtml/buildlink3.mk"
PLIST.gnome=		yes
.endif

.if !empty(PKG_OPTIONS:Mmng)
.include "../../graphics/mng/buildlink3.mk"
PLIST.mng=		yes
.endif

.if !empty(PKG_OPTIONS:Msvg)
.include "../../graphics/librsvg/buildlink3.mk"
PLIST.svg=		yes
.endif
