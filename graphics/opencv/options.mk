# $NetBSD: options.mk,v 1.5 2015/02/05 03:51:13 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opencv
PKG_SUPPORTED_OPTIONS=	python ffmpeg

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	python
.if !empty(PKG_OPTIONS:Mpython)
CMAKE_ARGS+=	-DPYTHON_EXECUTABLE:FILEPATH=${PYTHONBIN}
PY_PATCHPLIST=	yes
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
PLIST.python=	yes
.else
CMAKE_ARGS+=	-D BUILD_NEW_PYTHON_SUPPORT=OFF
.endif

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
