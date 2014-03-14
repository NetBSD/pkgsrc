# $NetBSD: options.mk,v 1.1 2014/03/14 14:54:02 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.freetype2
PKG_SUPPORTED_OPTIONS=	png subpixel

.include "../../mk/bsd.options.mk"

# subpixel (lcd) rendering, patent issues
.if !empty(PKG_OPTIONS:Msubpixel)
CFLAGS+=	-DFT_CONFIG_OPTION_SUBPIXEL_RENDERING
.endif

.if !empty(PKG_OPTIONS:Mpng)
CONFIGURE_ARGS+= --enable-png=yes
.include "../../graphics/png/buildlink3.mk"
.else
CONFIGURE_ARGS+= --enable-png=no
.endif
