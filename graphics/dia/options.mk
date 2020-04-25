# $NetBSD: options.mk,v 1.9 2020/04/25 10:51:42 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dia
PKG_SUPPORTED_OPTIONS=	cairo
PKG_SUGGESTED_OPTIONS=	cairo

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		cairo

.if !empty(PKG_OPTIONS:Mcairo)
CONFIGURE_ARGS+=	--with-cairo
.  include "../../graphics/cairo/buildlink3.mk"
PLIST.cairo=		yes
.else
CONFIGURE_ARGS+=	--without-cairo
.endif
