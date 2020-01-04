# $NetBSD: platform.mk,v 1.5 2020/01/04 02:06:02 nia Exp $

.if !defined(PLATFORM_SUPPORTS_WAYLAND)
.  include "../../mk/bsd.fast.prefs.mk"

# Please only add operating systems here after verifying that both
# devel/wayland and devel/wayland-protocols build.
WAYLAND_PLATFORMS+=		Linux-*-*

.if ${OPSYS} == "NetBSD" && empty(OS_VERSION:M[0-8].*)
PLATFORM_SUPPORTS_WAYLAND=	yes
.endif

.  for _wayland_platform in ${WAYLAND_PLATFORMS}
.    if !empty(MACHINE_PLATFORM:M${_wayland_platform})
PLATFORM_SUPPORTS_WAYLAND=	yes
.    endif
.  endfor
PLATFORM_SUPPORTS_WAYLAND?=	no

.endif # !defined(PLATFORM_SUPPORTS_WAYLAND)
