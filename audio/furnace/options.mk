# $NetBSD: options.mk,v 1.1 2024/11/12 21:27:33 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.furnace
PKG_SUPPORTED_OPTIONS=	jack
PKG_SUGGESTED_OPTIONS=	jack

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjack)
CMAKE_CONFIGURE_ARGS+=	-DWITH_JACK=ON
.  include "../../audio/jack/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_JACK=OFF
.endif
