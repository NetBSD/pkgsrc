# $NetBSD: options.mk,v 1.1 2024/07/21 12:07:40 tsutsui Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nanotodon
PKG_SUPPORTED_OPTIONS=	libwebp sixel
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibwebp)
.include "../../graphics/libwebp/buildlink3.mk"
CFLAGS+=	-DUSE_WEBP
MAKE_ENV+=	LDLIBS=-lwebp
.endif

.if !empty(PKG_OPTIONS:Msixel)
CFLAGS+=	-DUSE_SIXEL
.endif
