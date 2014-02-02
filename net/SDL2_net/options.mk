# $NetBSD: options.mk,v 1.1 2014/02/02 15:56:29 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.SDL2_net
PKG_SUPPORTED_OPTIONS=	static tests
PKG_SUGGESTED_OPTIONS+=	static

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mstatic)
CONFIGURE_ARGS+=	--enable-static=yes
.else
CONFIGURE_ARGS+=        --enable-static=no
.endif

.if !empty(PKG_OPTIONS:Mtests)
.include "../../graphics/GUIlib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gui=yes
.else
CONFIGURE_ARGS+=	--enable-gui=no --disable-sdltest
.endif
