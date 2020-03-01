# $NetBSD: options.mk,v 1.11 2020/03/01 15:36:01 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opencv
PKG_SUPPORTED_OPTIONS=	ffmpeg jasper

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mffmpeg)
CMAKE_ARGS+=	-DWITH_FFMPEG=ON
CMAKE_ARGS+=	-DFFMPEG_INCLUDE_DIR=${PREFIX}/include/ffmpeg4
CMAKE_ARGS+=	-DFFMPEG_LIB_DIR=${PREFIX}/lib/ffmpeg4
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_FFMPEG=OFF
.endif

.if !empty(PKG_OPTIONS:Mjasper)
CMAKE_ARGS+=	-DWITH_JASPER=ON
# jasper uses SIZE_MAX and friends in its headers.
CXXFLAGS+=	-D__STDC_LIMIT_MACROS
.include "../../graphics/jasper/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_JASPER=OFF
.endif

# FIXME: should be option.mk'ed instead
CMAKE_ARGS+=	-DBUILD_DOCS=OFF
