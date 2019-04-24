# $NetBSD: options.mk,v 1.7 2019/04/24 19:34:44 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opencv
PKG_SUPPORTED_OPTIONS=	ffmpeg

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mffmpeg)
CMAKE_ARGS+=	-DWITH_FFMPEG=ON
CMAKE_ARGS+=	-DFFMPEG_INCLUDE_DIR=${PREFIX}/include/ffmpeg2
CMAKE_ARGS+=	-DFFMPEG_LIB_DIR=${PREFIX}/lib/ffmpeg2
.include "../../multimedia/ffmpeg2/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_FFMPEG=OFF
.endif

# FIXME: should be option.mk'ed instead
CMAKE_ARGS+=	-DBUILD_DOCS=OFF
