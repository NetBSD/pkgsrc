# $NetBSD: options.mk,v 1.3 2024/08/25 06:19:03 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.raspberrypi-userland
PKG_SUPPORTED_OPTIONS=		debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Debug
.else
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
.endif
