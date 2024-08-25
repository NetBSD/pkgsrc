# $NetBSD: options.mk,v 1.5 2024/08/25 06:19:04 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gerbera

PKG_SUPPORTED_OPTIONS=	debug ffmpeg ffmpegthumbnailer javascript matroska systemd
PKG_SUGGESTED_OPTIONS=	javascript matroska

.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Mdebug)
CMAKE_CONFIGURE_ARGS+=	-DWITH_DEBUG=OFF
.endif

.if !empty(PKG_OPTIONS:Mffmpeg)
CMAKE_CONFIGURE_ARGS+=	-DWITH_AVCODEC=ON
.  include "../../multimedia/ffmpeg4/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mffmpegthumbnailer)
CMAKE_CONFIGURE_ARGS+=	-DWITH_FFMPEGTHUMBNAILER=ON
.  include "../../multimedia/ffmpegthumbnailer/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mjavascript)
CMAKE_CONFIGURE_ARGS+=	-DWITH_JS=OFF
.  include "../../lang/libduktape/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmatroska)
.  include "../../multimedia/libmatroska/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_MATROSKA=OFF
.endif

.if empty(PKG_OPTIONS:Msystemd)
CMAKE_CONFIGURE_ARGS+=	-DWITH_SYSTEMD=OFF
.endif
