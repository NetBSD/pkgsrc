# $NetBSD: options.mk,v 1.1 2020/05/31 15:20:22 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libretro-flycast
PKG_OPTIONS_REQUIRED_GROUPS=	gl
PKG_OPTIONS_GROUP.gl=		opengl

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "NetBSD" && !empty(MACHINE_ARCH:M*arm*)
PKG_OPTIONS_GROUP.gl+=		rpi
.endif

PKG_SUGGESTED_OPTIONS+=		opengl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopengl)
.  include "../../graphics/MesaLib/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mrpi)
MAKE_FLAGS+=	GLES=1
MAKE_FLAGS+=	GL_LIB="-lbrcmGLESv2"
.  include "../../misc/raspberrypi-userland/buildlink3.mk"
.endif
