# $NetBSD: platform.mk,v 1.3 2019/11/03 10:39:32 rillig Exp $

.if !defined(PLATFORM_SUPPORTS_WAYLAND)

# Please only add operating systems here after verifying that both
# devel/wayland and devel/wayland-protocols build.
.  for _wayland_os in NetBSD Linux
WAYLAND_PLATFORMS+=		${_wayland_os}-*-*
.  endfor

.  for _wayland_platform in ${WAYLAND_PLATFORMS}
.    if !empty(MACHINE_PLATFORM:M${_wayland_platform})
PLATFORM_SUPPORTS_WAYLAND=	yes
.    endif
.  endfor
PLATFORM_SUPPORTS_WAYLAND?=	no

.endif # !defined(PLATFORM_SUPPORTS_WAYLAND)
