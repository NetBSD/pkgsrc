# $NetBSD: options.mk,v 1.83 2022/03/13 15:50:05 tnn Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.MesaLib

.include "features.mk"

PKG_SUPPORTED_OPTIONS+=		elf-tls llvm vulkan x11

.if ${MESALIB_SUPPORTS_DRI} == "yes"
PKG_SUPPORTED_OPTIONS+=		wayland
.  include "../../devel/wayland/platform.mk"
.  if ${PLATFORM_SUPPORTS_WAYLAND} == "yes"
PKG_SUGGESTED_OPTIONS+=		wayland
.  endif
.endif

PKG_SUGGESTED_OPTIONS+=		x11

.include "../../mk/bsd.fast.prefs.mk"

# The LLVM option enables JIT accelerated software rendering and is also
# required to support the latest RADEON GPUs.
#
# Enable it by default on platforms where such GPUs might be encountered or
# LLVM-accelerated software rendering might be useful.
.if ${MESALIB_SUPPORTS_DRI} == "yes" && \
    ${OPSYS} != "SunOS" && \
      (${MACHINE_ARCH} == "i386" || \
       ${MACHINE_ARCH} == "x86_64" || \
       ${MACHINE_ARCH} == "aarch64")
PKG_SUGGESTED_OPTIONS+=		llvm
.endif

# ELF TLS is broken in at least the following cases:
# - NetBSD with SDL2 without X11
# - FreeBSD - https://gitlab.freedesktop.org/mesa/mesa/-/merge_requests/3559
# - Linux with musl libc
#
# https://gitlab.freedesktop.org/mesa/mesa/issues/966
.if ${OPSYS} == "Linux" && !empty(GLIBC_VERSION)
PKG_SUGGESTED_OPTIONS+=		elf-tls
.endif

.include "../../mk/bsd.options.mk"

# Gallium drivers requiring LLVM
PLIST_VARS+=	r600 radeonsi

# Windowing systems
PLIST_VARS+=	glx

# Misc. features
PLIST_VARS+=	vdpau

#
# ELF TLS support
#
.if empty(PKG_OPTIONS:Melf-tls)
BUILDLINK_TRANSFORM+=	rm:-DUSE_ELF_TLS
.endif

#
# LLVM support
#
.if !empty(PKG_OPTIONS:Mllvm)
MESON_ARGS+=		-Dllvm=enabled
.  include "../../devel/libelf/buildlink3.mk"
.  include "../../lang/libLLVM/buildlink3.mk"

.  if ${OPSYS} != "Darwin" && ${OPSYS} != "Cygwin"
# This is the latest libdrm requirement for amdgpu.
BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.107

PLIST.r600=		yes
GALLIUM_DRIVERS+=	r600
PLIST.radeonsi=		yes
GALLIUM_DRIVERS+=	radeonsi
.  endif
.else
MESON_ARGS+=		-Dllvm=disabled
.endif

#
# Vulkan support - experimental
#
PLIST_VARS+=		 vulkan vulkan_intel
.if !empty(PKG_OPTIONS:Mvulkan)
VULKAN_DRIVERS+=	amd
VULKAN_DRIVERS+=	swrast
PLIST.vulkan=		yes
.  if ${MACHINE_ARCH} == "x86_64"
VULKAN_DRIVERS+=	intel
PLIST.vulkan_intel=	yes
.  endif
.  if ${MACHINE_ARCH} == "aarch64"
VULKAN_DRIVERS+=	broadcom
VULKAN_DRIVERS+=	freedreno
.  endif
.endif

#
# X11 support
#
.if !empty(PKG_OPTIONS:Mx11)
MESA_PLATFORMS+=	x11
PLIST.glx=		yes
.  if ${MESALIB_SUPPORTS_DRI} == "yes"
MESON_ARGS+=		-Dglx=dri
.    include "../../multimedia/libvdpau/available.mk"
.    if ${VDPAU_AVAILABLE} == "yes"
MESON_ARGS+=		-Dgallium-vdpau=true
PLIST.vdpau=		yes
.      include "../../multimedia/libvdpau/buildlink3.mk"
.    else
MESON_ARGS+=		-Dgallium-vdpau=false
.    endif
.  endif
.  include "../../x11/libX11/buildlink3.mk"
.  include "../../x11/libXdamage/buildlink3.mk"
.  include "../../x11/libXext/buildlink3.mk"
.  include "../../x11/libXfixes/buildlink3.mk"
.  include "../../x11/libXrandr/buildlink3.mk"
.  include "../../x11/libXxf86vm/buildlink3.mk"
.  include "../../x11/libxcb/buildlink3.mk"
.  include "../../x11/libxshmfence/buildlink3.mk"
.  include "../../x11/xcb-proto/buildlink3.mk"
.  include "../../x11/xorgproto/buildlink3.mk"
.else
MESON_ARGS+=		-Dglx=disabled
MESON_ARGS+=		-Dgallium-vdpau=false
.endif

#
# Wayland support
#
.if !empty(PKG_OPTIONS:Mwayland)
MESA_PLATFORMS+=	wayland
.  include "../../devel/wayland/buildlink3.mk"
.  include "../../devel/wayland-protocols/buildlink3.mk"
.endif
