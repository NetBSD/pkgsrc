# $NetBSD: options.mk,v 1.3 2023/07/09 15:39:45 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libretro-flycast

.include "../../mk/bsd.fast.prefs.mk"

PKG_OPTIONS_REQUIRED_GROUPS+=	gl
PKG_OPTIONS_GROUP.gl+=		opengl

.if ${OPSYS} == "NetBSD" && !empty(MACHINE_ARCH:M*arm*)
PKG_OPTIONS_GROUP.gl+=		rpi
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-*-earmv6hf)
PKG_SUGGESTED_OPTIONS+=		rpi
.elif ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS+=		opengl
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mrpi)
CMAKE_ARGS+=	-DUSE_VIDEOCORE=ON
CMAKE_ARGS+=	-DUSE_GLES2=ON
CMAKE_ARGS+=	-DUSE_OPENGL=OFF
.  include "../../misc/raspberrypi-userland/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mopengl)
CMAKE_ARGS+=	-DUSE_OPENGL=ON
.  if ${OPSYS} != "Darwin"
.    include "../../graphics/MesaLib/buildlink3.mk"
.  endif
.endif
