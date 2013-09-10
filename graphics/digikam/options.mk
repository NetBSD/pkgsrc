# $NetBSD: options.mk,v 1.5 2013/09/10 11:23:20 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.digikam
PKG_SUPPORTED_OPTIONS=	debug lensfun liblqr pim
PKG_SUGGESTED_OPTIONS=	liblqr pim

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Debug
.endif

.if !empty(PKG_OPTIONS:Mlensfun)
.include "../../graphics/lensfun/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_LensFun:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mliblqr)
.include "../../graphics/liblqr/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_Lqr-1:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mpim)
.include "../../misc/kdepimlibs4/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_KdepimLibs:BOOL=OFF
.endif
