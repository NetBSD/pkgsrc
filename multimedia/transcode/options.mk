# $NetBSD: options.mk,v 1.6 2009/07/07 16:38:29 drochner Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.transcode
PKG_SUPPORTED_OPTIONS=	a52 freetype2 mjpegtools lzo libxml2
PKG_SUPPORTED_OPTIONS+=	dv imagemagick

PKG_SUGGESTED_OPTIONS=	a52 freetype2 mjpegtools libxml2
PKG_SUGGESTED_OPTIONS+=	imagemagick

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

.if !empty(PKG_OPTIONS:Ma52)
.  include "../../audio/liba52/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-a52
CONFIGURE_ARGS+=	--enable-a52-default-decoder
PLIST.a52=		yes
.else
CONFIGURE_ARGS+=	--disable-a52
.endif

.if !empty(PKG_OPTIONS:Mfreetype2)
.  include "../../graphics/freetype2/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-freetype2
PLIST.freetype2=	yes
.else
CONFIGURE_ARGS+=	--disable-freetype2
.endif

.if !empty(PKG_OPTIONS:Mmjpegtools)
.  include "../../multimedia/mjpegtools/buildlink3.mk"
PLIST.mjpegtools=	yes
CONFIGURE_ARGS+=	--enable-mjpegtools
.else
CONFIGURE_ARGS+=	--disable-mjpegtools
.endif

.if !empty(PKG_OPTIONS:Mlzo)
.  include "../../archivers/lzo/buildlink3.mk"
PLIST.lzo=		yes
CONFIGURE_ARGS+=	--enable-lzo
CONFIGURE_ARGS+=	--with-lzo-prefix=${BUILDLINK_PREFIX.lzo}
.else
CONFIGURE_ARGS+=	--disable-lzo
.endif

.if !empty(PKG_OPTIONS:Mlibxml2)
.  include "../../textproc/libxml2/buildlink3.mk"
PLIST.libxml2=		yes
CONFIGURE_ARGS+=	--enable-libxml2
.else
CONFIGURE_ARGS+=	--disable-libxml2
.endif

.if !empty(PKG_OPTIONS:Mdv)
.  include "../../multimedia/libdv/buildlink3.mk"
PLIST.dv=		yes
CONFIGURE_ARGS+=	--enable-libdv
.else
CONFIGURE_ARGS+=	--disable-libdv
.endif

.if !empty(PKG_OPTIONS:Mimagemagick)
.  include "../../graphics/ImageMagick/buildlink3.mk"
PLIST.imagemagick=	yes
CONFIGURE_ARGS+=	--enable-imagemagick
.else
CONFIGURE_ARGS+=	--disable-imagemagick
.endif
