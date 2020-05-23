# $NetBSD: options.mk,v 1.3 2020/05/23 13:05:19 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gmpc
PKG_SUPPORTED_OPTIONS=	mac xspf

.include "../../mk/bsd.options.mk"

###
### mac support
###
.if !empty(PKG_OPTIONS:Mmac)
.include "../../audio/mac/buildlink3.mk"
.endif

###
### libspiff support
###
.if !empty(PKG_OPTIONS:Mxspf)
.include "../../audio/libxspf/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libxspf
.else
CONFIGURE_ARGS+=	--disable-libxspf
.endif
