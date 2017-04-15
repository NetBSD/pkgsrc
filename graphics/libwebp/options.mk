# $NetBSD: options.mk,v 1.2 2017/04/15 15:56:00 kim Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libwebp
PKG_SUPPORTED_OPTIONS=	tiff
PKG_SUGGESTED_OPTIONS=	tiff

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtiff)
.include "../../graphics/tiff/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-tiff
.endif
