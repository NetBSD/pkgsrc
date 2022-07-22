# $NetBSD: options.mk,v 1.1 2022/07/22 20:18:54 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gimp
PKG_SUPPORTED_OPTIONS=	aalib mng xpm
PKG_SUGGESTED_OPTIONS=	mng xpm

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		aalib mng xpm

.if !empty(PKG_OPTIONS:Maalib)
.include "../../graphics/aalib/buildlink3.mk"
PLIST.aalib=		yes
.endif

.if !empty(PKG_OPTIONS:Mmng)
.include "../../graphics/mng/buildlink3.mk"
PLIST.mng=		yes
.endif

.if !empty(PKG_OPTIONS:Mxpm)
.include "../../x11/libXpm/buildlink3.mk"
PLIST.xpm=		yes
.endif
