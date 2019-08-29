# $NetBSD: platform.mk,v 1.1 2019/08/29 12:04:38 nia Exp $

.if !defined(PLATFORM_SUPPORTS_WAYLAND)

# Please only add operating systems here after verifying that both
# devel/wayland and devel/wayland-protocols build.
.for _wayland_os in NetBSD
WAYLAND_PLATFORMS+=		${_wayland_os}-*-*
.endfor

.for _wayland_platform in ${WAYLAND_PLATFORMS}
.if !empty(MACHINE_PLATFORM:M${_wayland_platform})
PLATFORM_SUPPORTS_WAYLAND=	yes
.endif
.endfor
PLATFORM_SUPPORTS_WAYLAND?=	no

.endif # !defined(PLATFORM_SUPPORTS_WAYLAND)
