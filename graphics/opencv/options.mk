# $NetBSD: options.mk,v 1.6 2015/10/08 17:45:59 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opencv
PKG_SUPPORTED_OPTIONS=	ffmpeg

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mffmpeg)
CMAKE_ARGS+=	-D WITH_FFMPEG=ON
CMAKE_ARGS+=	-D FFMPEG_INCLUDE_DIR=${PREFIX}/include/ffmpeg2
CMAKE_ARGS+=	-D FFMPEG_LIB_DIR=${PREFIX}/lib/ffmpeg2
.include "../../multimedia/ffmpeg2/buildlink3.mk"
.else
CMAKE_ARGS+=	-D WITH_FFMPEG=OFF
.endif

# FIXME: should be option.mk'ed instead
CMAKE_ARGS+=	-D BUILD_DOCS=OFF
