# $NetBSD: options.mk,v 1.10 2020/02/13 09:23:46 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opencv
PKG_SUPPORTED_OPTIONS=	ffmpeg

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mffmpeg)
CMAKE_ARGS+=	-DWITH_FFMPEG=ON
CMAKE_ARGS+=	-DFFMPEG_INCLUDE_DIR=${PREFIX}/include/ffmpeg4
CMAKE_ARGS+=	-DFFMPEG_LIB_DIR=${PREFIX}/lib/ffmpeg4
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_FFMPEG=OFF
.endif

# FIXME: should be option.mk'ed instead
CMAKE_ARGS+=	-DBUILD_DOCS=OFF
