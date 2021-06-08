# $NetBSD: options.mk,v 1.1 2021/06/08 10:12:55 bouyer Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mosquitto
PKG_SUPPORTED_OPTIONS=	websockets
PKG_SUGGESTED_OPTIONS=	websockets

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mwebsockets)
CMAKE_ARGS+=	-DWITH_WEBSOCKETS=yes
.include "../../www/libwebsockets/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_WEBSOCKETS=no
.endif
