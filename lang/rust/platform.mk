# $NetBSD: platform.mk,v 1.3 2020/05/19 22:29:05 nia Exp $

.if !defined(PLATFORM_SUPPORTS_RUST)

# Rust needs NetBSD>7
.  for _rust_arch in aarch64 armv7 i386 powerpc sparc64 x86_64
.    for _rust_os in Darwin FreeBSD Linux NetBSD SunOS
.      if ${OPSYS} != "NetBSD" || empty(OS_VERSION:M[0-7].*)
RUST_PLATFORMS+=	${_rust_os}-*-${_rust_arch}
.      endif
.    endfor
.  endfor

.  for _rust_platform in ${RUST_PLATFORMS}
.    if !empty(MACHINE_PLATFORM:M${_rust_platform})
PLATFORM_SUPPORTS_RUST=		yes
.    endif
.  endfor
PLATFORM_SUPPORTS_RUST?=	no

.endif # !defined(PLATFORM_SUPPORTS_RUST)
