# $NetBSD: options.mk,v 1.1 2023/02/12 14:42:25 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.occt
PKG_SUPPORTED_OPTIONS=	x11 occt-draw
PKG_SUGGESTED_OPTIONS=	occt-draw

.if ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS+=	x11
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
.include "../../graphics/freeimage/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
CMAKE_ARGS+=	-DUSE_XLIB=ON
CMAKE_ARGS+=	-DUSE_FREEIMAGE=ON
.else
CMAKE_ARGS+=	-DUSE_XLIB=OFF
CMAKE_ARGS+=	-DUSE_FREEIMAGE=OFF
.endif

.if !empty(PKG_OPTIONS:Mocct-draw)
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
CMAKE_ARGS+=	-DUSE_TCL=ON
CMAKE_ARGS+=	-DUSE_TK=ON
CMAKE_ARGS+=	-D3RDPARTY_TCL_INCLUDE_DIR=${BUILDLINK_PREFIX.tcl}/include
CMAKE_ARGS+=	-D3RDPARTY_TCL_LIBRARY_DIR=${BUILDLINK_PREFIX.tcl}/lib
CMAKE_ARGS+=	-D3RDPARTY_TK_INCLUDE_DIR=${BUILDLINK_PREFIX.tk}/include
CMAKE_ARGS+=	-D3RDPARTY_TK_LIBRARY_DIR=${BUILDLINK_PREFIX.tk}/lib
.  if ${OPSYS} == "Darwin"
CMAKE_ARGS+=	-D3RDPARTY_TCL_LIBRARY=${BUILDLINK_PREFIX.tcl}/lib/libtcl86.dylib
CMAKE_ARGS+=	-D3RDPARTY_TK_LIBRARY=${BUILDLINK_PREFIX.tk}/lib/libtk86.dylib
.  elif ${OPSYS} == "SunOS"
CMAKE_ARGS+=	-D3RDPARTY_TCL_LIBRARY=${BUILDLINK_PREFIX.tcl}/lib/libtcl86.so
CMAKE_ARGS+=	-D3RDPARTY_TK_LIBRARY=${BUILDLINK_PREFIX.tk}/lib/libtk86.so
.  endif
.else
CMAKE_ARGS+=	-DUSE_TCL=OFF
CMAKE_ARGS+=	-DUSE_TK=OFF
.endif

# TODO
CMAKE_ARGS+=	-DUSE_VTK=OFF
CMAKE_ARGS+=	-DUSE_FFMPEG=OFF
