# $NetBSD: options.mk,v 1.2 2024/08/25 06:19:07 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mosquitto
PKG_SUPPORTED_OPTIONS=	websockets
PKG_SUGGESTED_OPTIONS=	websockets

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mwebsockets)
CMAKE_CONFIGURE_ARGS+=	-DWITH_WEBSOCKETS=yes
.include "../../www/libwebsockets/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_WEBSOCKETS=no
.endif
