# $NetBSD: options.mk,v 1.6 2023/11/09 20:10:32 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.freetype2
PKG_SUPPORTED_OPTIONS=	brotli png
PKG_SUGGESTED_OPTIONS=	brotli png

.include "../../mk/bsd.options.mk"

# Support decompression of WOFF2 streams.
.if !empty(PKG_OPTIONS:Mbrotli)
CONFIGURE_ARGS+=	--with-brotli=yes
.include "../../archivers/brotli/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-brotli=no
.endif

# Support bitmaps in OpenType fonts.
.if !empty(PKG_OPTIONS:Mpng)
CONFIGURE_ARGS+=	--with-png=yes
.include "../../graphics/png/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-png=no
.endif
