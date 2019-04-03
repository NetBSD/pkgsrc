# $NetBSD: options.mk,v 1.9 2019/04/03 06:02:29 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gimp
PKG_SUPPORTED_OPTIONS=	aalib mng
PKG_SUGGESTED_OPTIONS=	mng

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		aalib mng

.if !empty(PKG_OPTIONS:Maalib)
.include "../../graphics/aalib/buildlink3.mk"
PLIST.aalib=		yes
.endif

.if !empty(PKG_OPTIONS:Mmng)
.include "../../graphics/mng/buildlink3.mk"
PLIST.mng=		yes
.endif
