# $NetBSD: options.mk,v 1.4 2015/02/05 21:02:37 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libretro-mupen64plus
PKG_OPTIONS_REQUIRED_GROUPS=	graphics
PKG_OPTIONS_GROUP.graphics=	opengl

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(MACHINE_ARCH:M*arm*)
PKG_OPTIONS_GROUP.graphics+=	rpi
PKG_SUPPORTED_OPTIONS+=	dynarec
PKG_SUGGESTED_OPTIONS+=	rpi dynarec
MUPEN64_DYNAREC_ARCH=	arm
.elif !empty(MACHINE_ARCH:Mi386)
PKG_SUPPORTED_OPTIONS+=	dynarec
PKG_SUGGESTED_OPTIONS+=	dynarec opengl
MUPEN64_DYNAREC_ARCH=	x86
.elif !empty(MACHINE_ARCH:Mx86_64)
PKG_SUPPORTED_OPTIONS+=	dynarec
PKG_SUGGESTED_OPTIONS+=	dynarec opengl
MUPEN64_DYNAREC_ARCH=	x86_64
.else
PKG_SUGGESTED_OPTIONS+=	opengl
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/MesaLib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mrpi)
MAKE_ENV+=	platform=rpi
.include "../../misc/raspberrypi-userland/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdynarec)
MAKE_ENV+=	WITH_DYNAREC=${MUPEN64_DYNAREC_ARCH}
.endif
