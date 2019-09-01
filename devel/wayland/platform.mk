# $NetBSD: platform.mk,v 1.2 2019/09/01 09:35:05 nia Exp $

.if !defined(PLATFORM_SUPPORTS_WAYLAND)

# Please only add operating systems here after verifying that both
# devel/wayland and devel/wayland-protocols build.
.for _wayland_os in NetBSD Linux
WAYLAND_PLATFORMS+=		${_wayland_os}-*-*
.endfor

.for _wayland_platform in ${WAYLAND_PLATFORMS}
.if !empty(MACHINE_PLATFORM:M${_wayland_platform})
PLATFORM_SUPPORTS_WAYLAND=	yes
.endif
.endfor
PLATFORM_SUPPORTS_WAYLAND?=	no

.endif # !defined(PLATFORM_SUPPORTS_WAYLAND)
