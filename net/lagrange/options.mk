# $NetBSD: options.mk,v 1.1 2021/07/16 16:00:33 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.lagrange

PKG_SUPPORTED_OPTIONS=	mpg123 opengl
PKG_SUGGESTED_OPTIONS=	mpg123

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmpg123)
.include "../../audio/mpg123/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_MPG123=ON
.else
CMAKE_ARGS+=	-DENABLE_MPG123=OFF
.endif

.if !empty(PKG_OPTIONS:Mopengl)
CMAKE_ARGS+=	-DENABLE_X11_SWRENDER=OFF
.else
CMAKE_ARGS+=	-DENABLE_X11_SWRENDER=ON
.endif
