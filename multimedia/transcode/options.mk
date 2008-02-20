# $NetBSD: options.mk,v 1.3 2008/02/20 10:20:04 xtraeme Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.transcode
PKG_SUPPORTED_OPTIONS=	a52 freetype2 mjpegtools mpeg3 lzo libxml2
PKG_SUPPORTED_OPTIONS+=	dv imagemagick

PKG_SUGGESTED_OPTIONS=	a52 freetype2 mjpegtools mpeg3 libxml2
PKG_SUGGESTED_OPTIONS+=	imagemagick

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Ma52)
.  include "../../audio/liba52/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-a52
CONFIGURE_ARGS+=	--enable-a52-default-decoder
PLIST_SUBST+=		A52=
.else
PLIST_SUBST+=		A52='@comment '
CONFIGURE_ARGS+=	--disable-a52
.endif

.if !empty(PKG_OPTIONS:Mfreetype2)
.  include "../../graphics/freetype2/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-freetype2
PLIST_SUBST+=		FREETYPE2=
.else
PLIST_SUBST+=		FREETYPE2='@comment '
CONFIGURE_ARGS+=	--disable-freetype2
.endif

.if !empty(PKG_OPTIONS:Mmjpegtools)
.  include "../../multimedia/mjpegtools/buildlink3.mk"
PLIST_SUBST+=		MJPEGTOOLS=
CONFIGURE_ARGS+=	--enable-mjpegtools
.else
PLIST_SUBST+=		MJPEGTOOLS='@comment '
CONFIGURE_ARGS+=	--disable-mjpegtools
.endif

.if !empty(PKG_OPTIONS:Mmpeg3)
BUILDLINK_API_DEPENDS.libmpeg3+=	libmpeg3>=1.7
PLIST_SUBST+=		MPEG3=
.  include "../../multimedia/libmpeg3/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libmpeg3-prefix=${BUILDLINK_PREFIX.libmpeg3}
CONFIGURE_ARGS+=	--enable-libmpeg3
.else
PLIST_SUBST+=		MPEG3='@comment '
CONFIGURE_ARGS+=	--disable-libmpeg3
.endif

.if !empty(PKG_OPTIONS:Mlzo)
PLIST_SUBST+=		LZO=
.  include "../../archivers/lzo/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-lzo
CONFIGURE_ARGS+=	--with-lzo-prefix==${BUILDLINK_PREFIX.lzo}
.else
PLIST_SUBST+=		LZO='@comment '
CONFIGURE_ARGS+=	--disable-lzo
.endif

.if !empty(PKG_OPTIONS:Mlibxml2)
PLIST_SUBST+=		LIBXML2=
.  include "../../textproc/libxml2/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libxml2
.else
PLIST_SUBST+=		LIBXML2='@comment '
CONFIGURE_ARGS+=	--disable-libxml2
.endif

.if !empty(PKG_OPTIONS:Mdv)
PLIST_SUBST+=	DV=
.  include "../../multimedia/libdv/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libdv
.else
PLIST_SUBST+=	DV='@comment '
CONFIGURE_ARGS+=	--disable-libdv
.endif

.if !empty(PKG_OPTIONS:Mimagemagick)
PLIST_SUBST+=		IMAGEMAGICK=
.  include "../../graphics/ImageMagick/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-imagemagick
.else
PLIST_SUBST+=		IMAGEMAGICK='@comment '
CONFIGURE_ARGS+=	--disable-imagemagick
.endif
