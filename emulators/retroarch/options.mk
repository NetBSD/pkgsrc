# $NetBSD: options.mk,v 1.1 2015/02/04 22:56:43 jmcneill Exp $

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.retroarch
PKG_SUPPORTED_OPTIONS=	sdl
PKG_SUGGESTED_OPTIONS=	sdl

.if !empty(MACHINE_ARCH:M*arm*)
PKG_SUPPORTED_OPTIONS+=	rpi
PKG_SUGGESTED_OPTIONS+=	rpi
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mrpi)
CONFIGURE_ARGS+=	--disable-x11
.include "../../misc/raspberrypi-userland/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msdl)
.include "../../devel/SDL/buildlink3.mk"
.endif
