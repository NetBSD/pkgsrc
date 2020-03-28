# $NetBSD: platform.mk,v 1.6 2020/03/28 08:58:25 maya Exp $

.if !defined(PLATFORM_SUPPORTS_WAYLAND)
.  include "../../mk/bsd.fast.prefs.mk"

.include "../../graphics/MesaLib/features.mk"

# Please only add operating systems here after verifying that both
# devel/wayland and devel/wayland-protocols build.
WAYLAND_PLATFORMS+=		Linux-*-*

# We can have Wayland without EGL, but a lot of things expect
# wayland and EGL support together.
.if ${OPSYS} == "NetBSD" && !empty(MESALIB_SUPPORTS_EGL:M[Yy][Ee][Ss])
PLATFORM_SUPPORTS_WAYLAND=	yes
.endif

.  for _wayland_platform in ${WAYLAND_PLATFORMS}
.    if !empty(MACHINE_PLATFORM:M${_wayland_platform})
PLATFORM_SUPPORTS_WAYLAND=	yes
.    endif
.  endfor
PLATFORM_SUPPORTS_WAYLAND?=	no

.endif # !defined(PLATFORM_SUPPORTS_WAYLAND)
