# $NetBSD: options.mk,v 1.4 2013/05/21 13:04:09 markd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.digikam
PKG_SUPPORTED_OPTIONS=	lensfun liblqr pim
PKG_SUGGESTED_OPTIONS=	liblqr pim

.include "../../mk/bsd.options.mk"

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
