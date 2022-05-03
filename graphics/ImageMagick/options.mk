# $NetBSD: options.mk,v 1.24 2022/05/03 08:27:11 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ImageMagick
PKG_SUPPORTED_OPTIONS=		djvu doc heif jp2 liblqr openexr tiff wmf x11
PKG_SUGGESTED_OPTIONS=		doc heif jp2 liblqr tiff x11

.include "../../mk/bsd.options.mk"

PLIST_SRC+=		PLIST

.if !empty(PKG_OPTIONS:Mdoc)
PLIST_SRC+=		PLIST.doc
.else
CONFIGURE_ARGS+=	--disable-docs
.endif

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

.if !empty(PKG_OPTIONS:Mtiff)
.include "../../graphics/tiff/buildlink3.mk"
CONFIGURE_ARGS+=	--with-tiff
.else
CONFIGURE_ARGS+=	--without-tiff
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
