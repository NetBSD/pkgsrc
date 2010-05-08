# $NetBSD: options.mk,v 1.8 2010/05/08 16:04:05 drochner Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.transcode
PKG_SUPPORTED_OPTIONS=	a52 freetype2 mjpegtools lzo libxml2
PKG_SUPPORTED_OPTIONS+=	dv imagemagick x264 faac

PKG_SUGGESTED_OPTIONS=	a52 freetype2 mjpegtools libxml2
PKG_SUGGESTED_OPTIONS+=	imagemagick x264

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

.if !empty(PKG_OPTIONS:Mx264)
.  include "../../multimedia/x264-devel/buildlink3.mk"
PLIST.x264=		yes
CONFIGURE_ARGS+=	--enable-x264
.else
CONFIGURE_ARGS+=
CONFIGURE_ARGS+=	--disable-x264
.endif

.if !empty(PKG_OPTIONS:Mfaac)
.  include "../../audio/faac/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-faac
.else
CONFIGURE_ARGS+=	--disable-faac
.endif
