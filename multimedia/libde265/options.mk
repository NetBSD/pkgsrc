# $NetBSD: options.mk,v 1.1 2026/06/05 08:19:13 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libde265
PKG_SUPPORTED_OPTIONS=	sdl2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msdl2)
.include "../../devel/SDL2/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DENABLE_SDL=OFF
.endif
