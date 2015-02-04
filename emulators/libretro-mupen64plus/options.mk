# $NetBSD: options.mk,v 1.1 2015/02/04 23:02:12 jmcneill Exp $

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.libretro-mupen64plus

.if !empty(MACHINE_ARCH:M*arm*)
PKG_SUPPORTED_OPTIONS+=	rpi dynarec
PKG_SUGGESTED_OPTIONS+=	rpi dynarec
MUPEN64_DYNAREC_ARCH=	arm
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mrpi)
MAKE_ENV+=	platform=rpi
.include "../../misc/raspberrypi-userland/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdynarec)
MAKE_ENV+=	WITH_DYNAREC=${MUPEN64_DYNAREC_ARCH}
.endif
