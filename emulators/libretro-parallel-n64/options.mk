# $NetBSD: options.mk,v 1.1 2020/05/31 16:03:04 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libretro-parallel-n64
PKG_OPTIONS_OPTIONAL_GROUPS=	gl
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
.else
MAKE_FLAGS+=	HAVE_OPENGL=0
.endif
