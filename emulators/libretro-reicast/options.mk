# $NetBSD: options.mk,v 1.3 2019/05/09 23:24:17 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libretro-reicast
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

.if !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/MesaLib/buildlink3.mk"
# Try to detect which GL versions are supported.
# OIT requires OpenGL 4.3
.  if !empty(BUILTIN_VERSION.Mesa)
MESA_MAJOR_VER=	${BUILTIN_VERSION.Mesa:C/\..*//gW}
.    if ${MESA_MAJOR_VER} >= 12
MAKE_FLAGS+=	HAVE_OIT=1
.    elif ${MESA_MAJOR_VER} >= 8
MAKE_FLAGS+=	HAVE_GL3=1
.    elif ${MESA_MAJOR_VER} >= 7
MAKE_FLAGS+=	HAVE_GL2=1
.    endif
.  else
MAKE_FLAGS+=	HAVE_GL3=1
.  endif
.elif !empty(PKG_OPTIONS:Mrpi)
MAKE_FLAGS+=	GLES=1
MAKE_FLAGS+=	GL_LIB="-lbrcmGLESv2"
.include "../../misc/raspberrypi-userland/buildlink3.mk"
.endif
