# $NetBSD: options.mk,v 1.9 2019/05/18 10:34:33 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libretro-mupen64plus
PKG_OPTIONS_REQUIRED_GROUPS=	graphics
PKG_OPTIONS_GROUP.graphics=	opengl

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(MACHINE_ARCH:M*arm*)
PKG_OPTIONS_GROUP.graphics+=	rpi
.endif

.if !empty(MACHINE_ARCH:Mearm*) && ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=		rpi
.else
PKG_SUGGESTED_OPTIONS+=		opengl
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mrpi)
MAKE_ENV+=	platform=rpi
.include "../../misc/raspberrypi-userland/buildlink3.mk"
.else
MAKE_ENV+=	platform=unix
.endif

.if !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/MesaLib/buildlink3.mk"
.endif
