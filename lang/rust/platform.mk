# $NetBSD: platform.mk,v 1.33 2025/06/16 21:10:43 he Exp $

# This file encodes whether a given platform has support for rust.

# Platforms where rust ought to work but does not require a link to an
# open PR.

.if !defined(PLATFORM_SUPPORTS_RUST)

# Rust needs NetBSD>8
.for rust_arch in aarch64 earmv6hf earmv7hf i386 powerpc riscv64 sparc64 x86_64
.  for rust_os in Darwin FreeBSD Linux NetBSD SunOS
.    if ${OPSYS} != "NetBSD" || empty(OS_VERSION:M[0-8].*)
RUST_PLATFORMS+=	${rust_os}-*-${rust_arch}
.    endif
.  endfor
.endfor

# rust does not build in the VA space available on earm.
# \todo Consider extension to other platforms.
.if ${NATIVE_MACHINE_PLATFORM:M*-*-earm*}
RUST_TYPE?=	bin
.endif

RUST_DIR?=	../../lang/rust

.for rust_platform in ${RUST_PLATFORMS}
.  if !empty(MACHINE_PLATFORM:M${rust_platform})
PLATFORM_SUPPORTS_RUST=		yes
.  endif
.endfor
PLATFORM_SUPPORTS_RUST?=	no

.endif # !defined(PLATFORM_SUPPORTS_RUST)
