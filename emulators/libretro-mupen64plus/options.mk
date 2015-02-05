# $NetBSD: options.mk,v 1.3 2015/02/05 17:33:12 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libretro-mupen64plus

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(MACHINE_ARCH:M*arm*)
PKG_SUPPORTED_OPTIONS+=	rpi dynarec
PKG_SUGGESTED_OPTIONS+=	rpi dynarec
MUPEN64_DYNAREC_ARCH=	arm
.elif !empty(MACHINE_ARCH:Mi386)
PKG_SUPPORTED_OPTIONS+=	dynarec
PKG_SUGGESTED_OPTIONS+=	dynarec
MUPEN64_DYNAREC_ARCH=	x86
.elif !empty(MACHINE_ARCH:Mx86_64)
PKG_SUPPORTED_OPTIONS+=	dynarec
PKG_SUGGESTED_OPTIONS+=	dynarec
MUPEN64_DYNAREC_ARCH=	x86_64
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mrpi)
MAKE_ENV+=	platform=rpi
.include "../../misc/raspberrypi-userland/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdynarec)
MAKE_ENV+=	WITH_DYNAREC=${MUPEN64_DYNAREC_ARCH}
.endif
