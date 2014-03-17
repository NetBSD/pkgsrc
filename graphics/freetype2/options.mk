# $NetBSD: options.mk,v 1.2.2.2 2014/03/17 09:30:55 tron Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.freetype2
PKG_SUPPORTED_OPTIONS=	png subpixel

.include "../../mk/bsd.options.mk"

# subpixel (lcd) rendering, patent issues
.if !empty(PKG_OPTIONS:Msubpixel)
CFLAGS+=	-DFT_CONFIG_OPTION_SUBPIXEL_RENDERING
.endif

.if !empty(PKG_OPTIONS:Mpng)
CONFIGURE_ARGS+= --with-png=yes
.include "../../graphics/png/buildlink3.mk"
.else
CONFIGURE_ARGS+= --with-png=no
.endif
