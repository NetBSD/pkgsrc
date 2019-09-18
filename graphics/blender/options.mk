# $NetBSD: options.mk,v 1.8 2019/09/18 23:40:17 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.blender
PKG_SUPPORTED_OPTIONS=		jack

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjack)
CMAKE_ARGS+=	-DWITH_JACK=ON
CMAKE_ARGS+=	-DWITH_JACK_DYNLOAD=OFF
.include "../../audio/jack/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_JACK=OFF
.endif
