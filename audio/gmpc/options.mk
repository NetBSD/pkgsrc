# $NetBSD: options.mk,v 1.1 2009/05/30 01:25:19 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gmpc
PKG_SUPPORTED_OPTIONS=	mac

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
### XXX: code not support libspiff>=1.0.
#.if !empty(PKG_OPTIONS:Mlibspiff)
#.include "../../audio/libspiff/buildlink3.mk"
#CONFIGURE_ARGS+=	--enable-libspiff
#.else
#CONFIGURE_ARGS+=	--disable-libspiff
#.endif
