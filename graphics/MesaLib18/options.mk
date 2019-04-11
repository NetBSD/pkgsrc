# $NetBSD: options.mk,v 1.12 2019/04/11 16:27:03 maya Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.MesaLib
PKG_SUPPORTED_OPTIONS=		llvm dri
PKG_SUGGESTED_OPTIONS=

PKG_SUPPORTED_OPTIONS+=		glx-tls xvmc debug
PKG_SUPPORTED_OPTIONS+=		vdpau vaapi
PKG_SUPPORTED_OPTIONS+=		osmesa
PKG_SUPPORTED_OPTIONS+=		glesv1 glesv2
PKG_SUPPORTED_OPTIONS+=		xa
PKG_SUPPORTED_OPTIONS+=		noatexit
PKG_SUPPORTED_OPTIONS+=		vulkan

# PKG_SUGGESTED_OPTIONS+=		xvmc
PKG_SUGGESTED_OPTIONS+=		vdpau vaapi
PKG_SUGGESTED_OPTIONS+=		glesv1 glesv2

PKG_SUGGESTED_OPTIONS+=		xa
PKG_SUGGESTED_OPTIONS+=		noatexit

# The LLVM option enables JIT accelerated software rendering and
# is also required to support the latest RADEON GPUs, so enable it
# by default on platforms where such GPUs might be encountered.
.if (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64") && \
	${OPSYS} != "SunOS" && ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS+=		llvm
.endif

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD" ||		\
	${OPSYS} == "DragonFly" || ${OPSYS} == "Linux" ||	\
	${OPSYS} == "SunOS" || ${OPSYS} == "NetBSD" ||		\
	${OPSYS} == "Darwin"
PKG_SUGGESTED_OPTIONS+=		dri
.endif


# Use Thread Local Storage in GLX where it is supported by Mesa and works.
.if \
	!empty(MACHINE_PLATFORM:MNetBSD-[789].*-i386) ||	\
	!empty(MACHINE_PLATFORM:MNetBSD-[789].*-x86_64) ||	\
	!empty(MACHINE_PLATFORM:MLinux-*-i386) ||		\
	!empty(MACHINE_PLATFORM:MLinux-*-x86_64) ||		\
	!empty(MACHINE_PLATFORM:MFreeBSD-1[0-9].*-x86_64) ||	\
	!empty(MACHINE_PLATFORM:MDragonFly-*-x86_64)
PKG_SUGGESTED_OPTIONS+=		glx-tls
.endif

.include "../../mk/bsd.options.mk"

# gallium
PLIST_VARS+=	freedreno i915 i965 nouveau r300 r600 radeonsi	\
		swrast svga vc4 virgl vulkan
# classic DRI
PLIST_VARS+=	dri swrast_dri nouveau_dri radeon_dri r200
# other features
PLIST_VARS+=	egl gbm vaapi vdpau wayland xatracker
PLIST_VARS+=	osmesa xvmc
PLIST_VARS+=	glesv1 glesv2

.if !empty(PKG_OPTIONS:Mdri)

CONFIGURE_ARGS+=	--enable-dri
# Having DRI3 and egl compiled in by default doesn't hurt, the X server
# will only use it if it is supported at run time.
CONFIGURE_ARGS+=	--enable-dri3
.if ${OPSYS} != "Darwin"
CONFIGURE_ARGS+=	--enable-egl
CONFIGURE_ARGS+=	--enable-gbm
PLIST.egl=		yes
PLIST.gbm=		yes
.else
CONFIGURE_ARGS+=	--disable-egl
CONFIGURE_ARGS+=	--disable-gbm
.endif

.if !empty(PKG_OPTIONS:Mosmesa)
CONFIGURE_ARGS+=	--enable-osmesa
PLIST.osmesa=		yes
.endif

.if !empty(PKG_OPTIONS:Mglesv1)
CONFIGURE_ARGS+=	--enable-gles1
PLIST.glesv1=		yes
.else
CONFIGURE_ARGS+=	--disable-gles1
.endif

.if !empty(PKG_OPTIONS:Mglesv2)
CONFIGURE_ARGS+=	--enable-gles2
PLIST.glesv2=		yes
.else
CONFIGURE_ARGS+=	--disable-gles2
.endif

.if !empty(PKG_OPTIONS:Mglx-tls)
# Recommended by
# http://www.freedesktop.org/wiki/Software/Glamor/
CONFIGURE_ARGS+=	--enable-glx-tls
.else
# (EE) Failed to load /usr/pkg/lib/xorg/modules/extensions/libglx.so:
# /usr/pkg/lib/libGL.so.1: Use of initialized Thread Local Storage with model
# initial-exec and dlopen is not supported
CONFIGURE_ARGS+=	--disable-glx-tls
.endif # glx-tls

# DRI on Linux needs either sysfs or udev
CONFIGURE_ARGS.Linux+=	--enable-sysfs

PLIST.dri=	yes

.if ${OPSYS} != "Darwin"
BUILDLINK_DEPMETHOD.libpciaccess=	full
.include "../../sysutils/libpciaccess/buildlink3.mk"
.endif
.include "../../graphics/MesaLib/dri.mk"

DRI_DRIVERS=		#
GALLIUM_DRIVERS=	#
VULKAN_DRIVERS=		#

# Software rasterizer
PLIST.swrast_dri=	yes
DRI_DRIVERS+=		swrast
.if ${OPSYS} != "Darwin"
PLIST.swrast=		yes
GALLIUM_DRIVERS+=	swrast
.endif

# x86 only drivers
.if (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64") && ${OPSYS} != "Darwin"
# svga / VMWare driver
PLIST.svga=		yes
GALLIUM_DRIVERS+=	svga

# Intel chipsets, x86 only
PLIST.i915=		yes
GALLIUM_DRIVERS+=	i915
DRI_DRIVERS+=		i915

PLIST.i965=		yes
DRI_DRIVERS+=		i965

.endif

# Vulkan support
.if !empty(PKG_OPTIONS:Mvulkan)
VULKAN_DRIVERS+=	intel
VULKAN_DRIVERS+=	radeon
PLIST.vulkan=		yes
.endif

# ARM drivers
.if !empty(MACHINE_PLATFORM:MNetBSD-*-*arm*)
# Qualcomm SnapDragon, libdrm_freedreno.pc
#GALLIUM_DRIVERS+=	freedreno
#PLIST.freedreno=	yes

# Broadcom VideoCore 4
GALLIUM_DRIVERS+=	vc4
PLIST.vc4=		yes
.endif

# qemu Linux guest driver
.if !empty(MACHINE_PLATFORM:MLinux-*-x86_64)
# XXX test this
#GALLIUM_DRIVERS+=	virgl
#PLIST.virgl=		yes
.endif

# theoretically cross platform PCI drivers
.if ${OPSYS} != "Darwin" && empty(MACHINE_PLATFORM:MNetBSD-*-*arm*) && \
	empty(MACHINE_PLATFORM:MNetBSD-*-mipsel)

# AMD Radeon r600
PLIST.r600=		yes
GALLIUM_DRIVERS+=	r600

# FULL_OS_VERSION_CMD=	${UNAME} -r
# FULL_OS_VERSION=	${FULL_OS_VERSION_CMD:sh}

# FreeBSD lacks nouveau support (there are official binaries from Nvidia)
.if ${OPSYS} != "FreeBSD"
# nVidia
PLIST.nouveau=		yes
GALLIUM_DRIVERS+=	nouveau
.endif

# classic DRI radeon
PLIST.radeon_dri=	yes
DRI_DRIVERS+=		radeon

# classic DRI r200
PLIST.r200=		yes
DRI_DRIVERS+=		r200

# FreeBSD lacks nouveau support (there are official binaries from Nvidia)
.if ${OPSYS} != "FreeBSD"
# classic DRI nouveau
PLIST.nouveau_dri=	yes
DRI_DRIVERS+=		nouveau
.endif
.endif # cross platform PCI drivers

.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--with-platforms=x11
#.elif ${OPSYS} == "Linux"
#.include "../../wip/wayland/buildlink3.mk"
#CONFIGURE_ARGS+=	--with-platforms=x11,drm,wayland
#PLIST.wayland=		yes
.else
CONFIGURE_ARGS+=	--with-platforms=x11,drm
.endif

.if !empty(PKG_OPTIONS:Mllvm)
# VA-API and VDPAU
.if !empty(PKG_OPTIONS:Mvaapi)
.include "../../multimedia/libva/available.mk"
.if ${VAAPI_AVAILABLE} == "yes"
PLIST.vaapi=	yes
.include "../../multimedia/libva/buildlink3.mk"
.endif
.endif # vaapi
.if !empty(PKG_OPTIONS:Mvdpau)
.include "../../multimedia/libvdpau/available.mk"
.if ${VDPAU_AVAILABLE} == "yes"
PLIST.vdpau=	yes
.include "../../multimedia/libvdpau/buildlink3.mk"
.endif
.endif # vdpau

# XA is useful for accelerating xf86-video-vmware
.if !empty(PKG_OPTIONS:Mxa)
CONFIGURE_ARGS+=	--enable-xa
PLIST.xatracker=	yes
.endif

# AMD Radeon r300
PLIST.r300=		yes
GALLIUM_DRIVERS+=	r300
# AMD Canary Islands GPUs
PLIST.radeonsi=		yes
GALLIUM_DRIVERS+=	radeonsi
CONFIGURE_ARGS+=	--enable-llvm
CONFIGURE_ARGS+=	--enable-llvm-shared-libs

.if !exists(/usr/include/libelf.h)
.include "../../devel/libelf/buildlink3.mk"
.endif

BUILDLINK_API_DEPENDS.libLLVM+= libLLVM>=7.0
.include "../../lang/libLLVM/buildlink3.mk"
CONFIGURE_ENV+=		ac_cv_path_ac_pt_LLVM_CONFIG=${LLVM_CONFIG_PATH}
.else # !llvm
CONFIGURE_ARGS+=	--disable-xa
CONFIGURE_ARGS+=	--disable-llvm
CONFIGURE_ARGS+=	--disable-llvm-shared-libs
.endif # llvm

CONFIGURE_ARGS+=	--with-gallium-drivers=${GALLIUM_DRIVERS:ts,}
CONFIGURE_ARGS+=	--with-dri-drivers=${DRI_DRIVERS:ts,}
CONFIGURE_ARGS+=	--with-vulkan-drivers=${VULKAN_DRIVERS:ts,}

.else # !dri
CONFIGURE_ARGS+=	--with-gallium-drivers=
CONFIGURE_ARGS+=	--with-dri-drivers=
CONFIGURE_ARGS+=	--with-vulkan-drivers=
CONFIGURE_ARGS+=	--disable-dri
CONFIGURE_ARGS+=	--disable-dri3
CONFIGURE_ARGS+=	--disable-egl
CONFIGURE_ARGS+=	--disable-gbm
CONFIGURE_ARGS+=	--disable-gles1
CONFIGURE_ARGS+=	--disable-gles2
CONFIGURE_ARGS+=	--enable-xlib-glx
CONFIGURE_ARGS+=	--with-platforms=x11
.if !empty(PKG_OPTIONS:Mllvm)
PKG_FAIL_REASON+=	"The llvm PKG_OPTION must also be disabled when dri is disabled"
.endif
.endif # dri

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Mxvmc)
.include "../../x11/libXvMC/buildlink3.mk"
PLIST.xvmc=		yes
.endif

.if !empty(PKG_OPTIONS:Mnoatexit)
CPPFLAGS+=	-DHAVE_NOATEXIT
.endif
