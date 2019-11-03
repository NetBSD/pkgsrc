# $NetBSD: options.mk,v 1.2 2019/11/03 17:04:26 rillig Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.raspberrypi-userland
PKG_SUPPORTED_OPTIONS=		debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Debug
.else
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
.endif
