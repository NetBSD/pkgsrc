# $NetBSD: options.mk,v 1.1 2017/04/15 15:48:12 kim Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libwebp
PKG_SUPPORTED_OPTIONS=	tiff

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtiff)
.include "../../graphics/tiff/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-tiff
.endif
