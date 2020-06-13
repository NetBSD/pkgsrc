# $NetBSD: options.mk,v 1.2 2020/06/13 10:45:19 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libretro-ppsspp
PKG_OPTIONS_REQUIRED_GROUPS=	gl
PKG_OPTIONS_GROUP.gl=		opengl

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(MACHINE_ARCH:Mearm*) && ${OPSYS} == "NetBSD"
PKG_OPTIONS_GROUP.gl+=	rpi
.endif

PKG_SUGGESTED_OPTIONS+=	opengl

.if ${MACHINE_ARCH} == "earmv7hf"
PKG_SUPPORTED_OPTIONS+=	simd
PKG_SUGGESTED_OPTIONS+=	simd
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msimd)
CFLAGS+=	-mfpu=neon -D__NEON_OPT
MAKE_FLAGS+=	HAVE_NEON=1
.endif

.if !empty(PKG_OPTIONS:Mrpi)
MAKE_FLAGS+=	GLES=1
MAKE_FLAGS+=	GL_LIB="-lbrcmGLESv2"
.include "../../misc/raspberrypi-userland/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/MesaLib/buildlink3.mk"
.endif
