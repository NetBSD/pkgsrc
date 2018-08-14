# $NetBSD: options.mk,v 1.1 2018/08/14 12:55:41 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libretro-ppsspp
PKG_OPTIONS_REQUIRED_GROUPS=	graphics
PKG_OPTIONS_GROUP.graphics=	opengl

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(MACHINE_ARCH:Mearm*)
PKG_OPTIONS_GROUP.graphics+=	rpi
.endif

.if !empty(MACHINE_ARCH:Mearm*) && ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=		rpi
.else
PKG_SUGGESTED_OPTIONS+=		opengl
.endif

.if ${MACHINE_ARCH} == "earmv7hf" || ${MACHINE_ARCH} == "earmv7hfeb"
PKG_SUPPORTED_OPTIONS+=		simd
PKG_SUGGESTED_OPTIONS+=		simd
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msimd)
CFLAGS+=	-mfpu=neon -D__NEON_OPT
MAKE_FLAGS+=	HAVE_NEON=1
.endif

.if !empty(PKG_OPTIONS:Mrpi)
BUILD_MAKE_FLAGS+=	platform=rpi
SUBST_CLASSES+=		vc
SUBST_STAGE.vc=		pre-configure
SUBST_MESSAGE.vc=	Fixing path to VideoCore libraries.
SUBST_FILES.vc=		libretro/Makefile
SUBST_SED.vc+=		-e 's;/opt/vc;${PREFIX};g'
.include "../../misc/raspberrypi-userland/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/MesaLib/buildlink3.mk"
.endif
