# $NetBSD: platform.mk,v 1.2 2019/11/03 19:04:07 rillig Exp $

.if !defined(PLATFORM_SUPPORTS_RUST)

.  for _rust_arch in aarch64 armv7 i386 powerpc sparc64 x86_64
.    for _rust_os in Darwin FreeBSD Linux NetBSD SunOS
RUST_PLATFORMS+=	${_rust_os}-*-${_rust_arch}
.    endfor
.  endfor

.  for _rust_platform in ${RUST_PLATFORMS}
.    if !empty(MACHINE_PLATFORM:M${_rust_platform})
PLATFORM_SUPPORTS_RUST=		yes
.    endif
.  endfor
PLATFORM_SUPPORTS_RUST?=	no

.endif # !defined(PLATFORM_SUPPORTS_RUST)
