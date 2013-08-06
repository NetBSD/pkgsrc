# $NetBSD: options.mk,v 1.1 2013/08/06 10:05:39 jmcneill Exp $

PKG_OPTIONS_VAR=	 	PKG_OPTIONS.raspberrypi-userland
PKG_SUPPORTED_OPTIONS=	 	debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Debug
.else
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
.endif
