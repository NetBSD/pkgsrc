# $NetBSD: options.mk,v 1.2 2013/10/01 16:03:30 drochner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gmpc
PKG_SUPPORTED_OPTIONS=	mac xspf

.include "../../mk/bsd.options.mk"

###
### mac support
###
.if !empty(PKG_OPTIONS:Mmac)
.include "../../audio/mac/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-macige
.else
CONFIGURE_ARGS+=	--disable-macige
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
