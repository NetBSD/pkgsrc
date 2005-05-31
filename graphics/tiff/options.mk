# $NetBSD: options.mk,v 1.2 2005/05/31 10:01:37 dillo Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tiff
PKG_SUPPORTED_OPTIONS=	lzw
PKG_SUGGESTED_OPTIONS=	lzw

.include "../../mk/bsd.options.mk"

###
### LZW compression support
###
.if !empty(PKG_OPTIONS:Mlzw)
CONFIGURE_ARGS+=	--enable-lzw
.else
CONFIGURE_ARGS+=	--disable-lzw
.endif
