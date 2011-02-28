# $NetBSD: options.mk,v 1.1 2011/02/28 17:49:30 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qemu
PKG_SUPPORTED_OPTIONS=	sdl

.include "../../mk/bsd.fast.prefs.mk"

.if empty(OPSYS:MDarwin)
PKG_SUGGESTED_OPTIONS=	sdl
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--enable-sdl
.include "../../devel/SDL/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-sdl
.endif
