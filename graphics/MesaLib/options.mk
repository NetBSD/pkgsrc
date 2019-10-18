# $NetBSD: options.mk,v 1.74 2019/10/18 09:57:07 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.MesaLib

PKG_SUPPORTED_OPTIONS+=		llvm vulkan x11

.if ${OPSYS} != "Darwin" && ${OPSYS} != "Cygwin"
PKG_SUPPORTED_OPTIONS+=		wayland
.endif

PKG_SUGGESTED_OPTIONS+=		x11

# The LLVM option enables JIT accelerated software rendering and is also
# required to support the latest RADEON GPUs.
#
# Enable it by default on platforms where such GPUs might be encountered or
# LLVM-accelerated software rendering might be useful.
.if ${OPSYS} != "SunOS" && \
    ${OPSYS} != "Darwin" && \
    ${OPSYS} != "Cygwin" && \
      (${MACHINE_ARCH} == "i386" || \
       ${MACHINE_ARCH} == "x86_64" || \
       ${MACHINE_ARCH} == "aarch64")
PKG_SUGGESTED_OPTIONS+=		llvm
.endif

.include "../../mk/bsd.options.mk"

# Gallium drivers requiring LLVM
PLIST_VARS+=	r600 radeonsi

# Windowing systems
PLIST_VARS+=	wayland glx

# Misc. features
PLIST_VARS+=	vdpau

#
# LLVM support
#
.if !empty(PKG_OPTIONS:Mllvm)
MESON_ARGS+=		-Dllvm=true
BUILDLINK_API_DEPENDS.libLLVM+=	libLLVM>=7.0.1nb2
.  include "../../devel/libelf/buildlink3.mk"
.  include "../../lang/libLLVM/buildlink3.mk"

.  if ${OPSYS} != "Darwin" && ${OPSYS} != "Cygwin"
# This is the latest libdrm requirement for amdgpu.
BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.99

PLIST.r600=		yes
GALLIUM_DRIVERS+=	r600
PLIST.radeonsi=		yes
GALLIUM_DRIVERS+=	radeonsi
.  endif
.else
MESON_ARGS+=		-Dllvm=false
.endif

#
# Vulkan support - experimental
#
.if !empty(PKG_OPTIONS:Mvulkan)
MESON_ARGS+=		-Dvulkan-drivers="auto"
.else
MESON_ARGS+=		-Dvulkan-drivers=""
.endif

#
# Wayland support
#
.if !empty(PKG_OPTIONS:Mwayland)
MESA_PLATFORMS+=	wayland
PLIST.wayland=		yes
.  include "../../devel/wayland/buildlink3.mk"
.  include "../../devel/wayland-protocols/buildlink3.mk"
.endif

#
# X11 support
#
.if !empty(PKG_OPTIONS:Mx11)
MESA_PLATFORMS+=	x11
PLIST.glx=		yes
.  if ${OPSYS} != "Darwin" && ${OPSYS} != "Cygwin"
MESON_ARGS+=		-Dglx=dri
.    include "../../multimedia/libvdpau/available.mk"
.    if ${OPSYS} != "SunOS" && ${VDPAU_AVAILABLE} == "yes"
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
