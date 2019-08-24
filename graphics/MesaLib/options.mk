# $NetBSD: options.mk,v 1.70 2019/08/24 20:01:01 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.MesaLib
PKG_SUPPORTED_OPTIONS=		llvm dri wayland
PKG_SUGGESTED_OPTIONS=

PKG_SUPPORTED_OPTIONS+=		vdpau vaapi
PKG_SUPPORTED_OPTIONS+=		osmesa
PKG_SUPPORTED_OPTIONS+=		glesv1 glesv2
PKG_SUPPORTED_OPTIONS+=		gallium-xa
PKG_SUPPORTED_OPTIONS+=		gallium-xvmc
PKG_SUPPORTED_OPTIONS+=		vulkan

PKG_SUGGESTED_OPTIONS+=		vdpau vaapi
PKG_SUGGESTED_OPTIONS+=		glesv1 glesv2

PKG_SUGGESTED_OPTIONS+=		gallium-xa
#PKG_SUGGESTED_OPTIONS+=	gallium-xvmc
PKG_SUGGESTED_OPTIONS+=		osmesa

PKG_OPTIONS_LEGACY_OPTS+=	xa:gallium-xa
PKG_OPTIONS_LEGACY_OPTS+=	xvmc:gallium-xvmc

# The LLVM option enables JIT accelerated software rendering and
# is also required to support the latest RADEON GPUs, so enable it
# by default on platforms where such GPUs might be encountered
# or accelerated software rendering might be useful.
.if (${MACHINE_ARCH} == "i386" || \
     ${MACHINE_ARCH} == "x86_64" || \
     ${MACHINE_ARCH} == "aarch64") && \
	${OPSYS} != "SunOS" && ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS+=		llvm
.endif

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD" ||		\
	${OPSYS} == "DragonFly" || ${OPSYS} == "Linux" ||	\
	${OPSYS} == "SunOS" || ${OPSYS} == "NetBSD" ||		\
	${OPSYS} == "Darwin"
PKG_SUGGESTED_OPTIONS+=		dri
.endif

.include "../../mk/bsd.options.mk"

# gallium
PLIST_VARS+=	freedreno i915 i965 nouveau r300 r600 radeonsi	\
		swrast svga vc4 virgl vulkan
# classic DRI
PLIST_VARS+=	dri swrast_dri nouveau_dri r100 r200
# other features
PLIST_VARS+=	egl gbm vaapi vdpau wayland xatracker
PLIST_VARS+=	osmesa xvmc
PLIST_VARS+=	glesv1 glesv2

EGL_PLATFORMS+=		x11

.if ${OPSYS} != "Darwin"
EGL_PLATFORMS+=		drm
.endif

.if !empty(PKG_OPTIONS:Mwayland)
EGL_PLATFORMS+=		wayland
PLIST.wayland=		yes
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdri)
# Having DRI3 and egl compiled in by default doesn't hurt, the X server
# will only use it if it is supported at run time.
MESON_ARGS+=		-Ddri3=true
.  if ${OPSYS} != "Darwin" && ${OPSYS} != "SunOS"
MESON_ARGS+=		-Degl=true
MESON_ARGS+=		-Dgbm=true
PLIST.egl=		yes
PLIST.gbm=		yes
.  else
MESON_ARGS+=		-Degl=false
MESON_ARGS+=		-Dgbm=false
.  endif

.  if !empty(PKG_OPTIONS:Mosmesa)
MESON_ARGS+=		-Dosmesa=classic
PLIST.osmesa=		yes
.  else
MESON_ARGS+=		-Dosmesa=none
.  endif

.  if !empty(PKG_OPTIONS:Mglesv1)
MESON_ARGS+=		-Dgles1=true
PLIST.glesv1=		yes
.  else
MESON_ARGS+=		-Dgles1=false
.  endif

.  if !empty(PKG_OPTIONS:Mglesv2)
MESON_ARGS+=		-Dgles2=true
PLIST.glesv2=		yes
.  else
MESON_ARGS+=		-Dgles2=false
.  endif

PLIST.dri=	yes

.  if ${OPSYS} != "Darwin"
BUILDLINK_DEPMETHOD.libpciaccess=	full
.    include "../../sysutils/libpciaccess/buildlink3.mk"
.  endif
.  include "../../graphics/MesaLib/dri.mk"

DRI_DRIVERS=		#
GALLIUM_DRIVERS=	#
VULKAN_DRIVERS=		#

# Software rasterizer
PLIST.swrast_dri=	yes
DRI_DRIVERS+=		swrast

# x86 only drivers
.  if (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64") && ${OPSYS} != "Darwin"
# svga / VMWare driver
PLIST.svga=		yes
GALLIUM_DRIVERS+=	svga

# Intel chipsets, x86 only
PLIST.i915=		yes
DRI_DRIVERS+=		i915

PLIST.i965=		yes
DRI_DRIVERS+=		i965

.  endif

# Vulkan support
.  if !empty(PKG_OPTIONS:Mvulkan)
VULKAN_DRIVERS+=	amd
VULKAN_DRIVERS+=	intel
PLIST.vulkan=		yes
.  endif

# ARM drivers
.  if !empty(MACHINE_PLATFORM:MNetBSD-*-*arm*)
# Qualcomm SnapDragon, libdrm_freedreno.pc
#GALLIUM_DRIVERS+=	freedreno
#PLIST.freedreno=	yes

# Broadcom VideoCore 4
GALLIUM_DRIVERS+=	vc4
PLIST.vc4=		yes
.  endif

# qemu Linux guest driver
.  if !empty(MACHINE_PLATFORM:MLinux-*-x86_64)
# XXX test this
#GALLIUM_DRIVERS+=	virgl
#PLIST.virgl=		yes
.  endif

# theoretically cross platform PCI drivers
.  if ${OPSYS} != "Darwin" && empty(MACHINE_PLATFORM:MNetBSD-*-*arm*) && \
	empty(MACHINE_PLATFORM:MNetBSD-*-mipsel)

# AMD Radeon r600
PLIST.r600=		yes
GALLIUM_DRIVERS+=	r600

# FULL_OS_VERSION_CMD=	${UNAME} -r
# FULL_OS_VERSION=	${FULL_OS_VERSION_CMD:sh}

# FreeBSD lacks nouveau support (there are official binaries from Nvidia)
.    if ${OPSYS} != "FreeBSD"
# nVidia
PLIST.nouveau=		yes
GALLIUM_DRIVERS+=	nouveau
.    endif

# classic DRI r100
PLIST.r100=		yes
DRI_DRIVERS+=		r100

# classic DRI r200
PLIST.r200=		yes
DRI_DRIVERS+=		r200

# FreeBSD lacks nouveau support (there are official binaries from Nvidia)
.    if ${OPSYS} != "FreeBSD"
# classic DRI nouveau
PLIST.nouveau_dri=	yes
DRI_DRIVERS+=		nouveau
.    endif
.  endif
# end cross platform PCI drivers

.  if !empty(PKG_OPTIONS:Mllvm)
# VA-API and VDPAU
.    if !empty(PKG_OPTIONS:Mvaapi)
.      include "../../multimedia/libva/available.mk"
.      if ${VAAPI_AVAILABLE} == "yes"
PLIST.vaapi=	yes
.        include "../../multimedia/libva/buildlink3.mk"
.      endif
.    endif # vaapi
.    if !empty(PKG_OPTIONS:Mvdpau)
.      include "../../multimedia/libvdpau/available.mk"
.      if ${VDPAU_AVAILABLE} == "yes"
PLIST.vdpau=	yes
.        include "../../multimedia/libvdpau/buildlink3.mk"
.      endif
.    endif # vdpau

# XA is useful for accelerating xf86-video-vmware
.    if !empty(PKG_OPTIONS:Mgallium-xa)
MESON_ARGS+=		-Dgallium-xa=true
PLIST.xatracker=	yes
.    else
MESON_ARGS+=		-Dgallium-xa=false
.    endif

# AMD Radeon r300
PLIST.r300=		yes
GALLIUM_DRIVERS+=	r300
# AMD Canary Islands GPUs
PLIST.radeonsi=		yes
GALLIUM_DRIVERS+=	radeonsi
MESON_ARGS+=		-Dllvm=true

BUILDLINK_API_DEPENDS.libLLVM+= libLLVM>=7.0.1nb2
.    include "../../devel/libelf/buildlink3.mk"
.    include "../../lang/libLLVM/buildlink3.mk"
.  else # !llvm
MESON_ARGS+=		-Dgallium-xa=false
MESON_ARGS+=		-Dgallium-vdpau=false
MESON_ARGS+=		-Dllvm=false
.  endif # llvm
PLIST_SUBST+=		GLVER="1.2.0"
MESON_ARGS+=		-Dgallium-drivers=${GALLIUM_DRIVERS:ts,}
MESON_ARGS+=		-Ddri-drivers=${DRI_DRIVERS:ts,}
MESON_ARGS+=		-Dvulkan-drivers=${VULKAN_DRIVERS:ts,}
MESON_ARGS+=		-Dplatforms=${EGL_PLATFORMS:ts,}
.else # !dri
PLIST_SUBST+=		GLVER="1.6.0"
MESON_ARGS+=		-Dgallium-drivers=
MESON_ARGS+=		-Ddri-drivers=
MESON_ARGS+=		-Dvulkan-drivers=
MESON_ARGS+=		-Ddri3=false
MESON_ARGS+=		-Degl=false
MESON_ARGS+=		-Dgbm=false
MESON_ARGS+=		-Dgles1=false
MESON_ARGS+=		-Dgles2=false
MESON_ARGS+=		-Dglx=xlib
MESON_ARGS+=		-Dplatforms=x11
MESON_ARGS+=		-Dllvm=false
.endif # dri

.if !empty(PKG_OPTIONS:Mgallium-xvmc)
MESON_ARGS+=		-Dgallium-xvmc=true
.include "../../x11/libXvMC/buildlink3.mk"
PLIST.xvmc=		yes
.else
MESON_ARGS+=		-Dgallium-xvmc=false
.endif
