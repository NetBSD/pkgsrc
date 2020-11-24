# $NetBSD: options.mk,v 1.21.2.1 2020/11/24 18:28:37 bsiegert Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ImageMagick
PKG_SUPPORTED_OPTIONS=		x11 jp2 djvu openexr wmf liblqr heif
PKG_SUGGESTED_OPTIONS=		x11 jp2 liblqr heif
PKG_OPTIONS_LEGACY_OPTS+=	jasper:jp2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif

.if !empty(PKG_OPTIONS:Mjp2)
.include "../../graphics/openjpeg/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openjp2
.else
CONFIGURE_ARGS+=	--without-openjp2
.endif

.if !empty(PKG_OPTIONS:Mliblqr)
.include "../../graphics/liblqr/buildlink3.mk"
CONFIGURE_ARGS+=	--with-lqr
.else
CONFIGURE_ARGS+=	--without-lqr
.endif

.if !empty(PKG_OPTIONS:Mdjvu)
.include "../../graphics/djvulibre-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-djvu
.else
CONFIGURE_ARGS+=	--without-djvu
.endif

.if !empty(PKG_OPTIONS:Mopenexr)
.include "../../graphics/openexr/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openexr
.else
CONFIGURE_ARGS+=	--without-openexr
.endif

.if !empty(PKG_OPTIONS:Mwmf)
.include "../../graphics/libwmf/buildlink3.mk"
CONFIGURE_ARGS+=	--with-wmf
.else
CONFIGURE_ARGS+=	--without-wmf
.endif

.if !empty(PKG_OPTIONS:Mheif)
.include "../../graphics/libheif/buildlink3.mk"
CONFIGURE_ARGS+=	--with-heic
.else
CONFIGURE_ARGS+=	--without-heic
.endif
