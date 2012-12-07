# $NetBSD: options.mk,v 1.3 2012/12/07 21:01:29 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opencv
PKG_SUPPORTED_OPTIONS=	python

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

# FIXME: should be option.mk'ed instead
CMAKE_ARGS+=	-D BUILD_DOXYGEN_DOCS=OFF
CMAKE_ARGS+=	-D WITH_FFMPEG=OFF
