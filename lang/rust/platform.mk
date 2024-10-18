# $NetBSD: platform.mk,v 1.29 2024/10/18 08:18:53 abs Exp $

# This file encodes whether a given platform has support for rust.

# Platforms where rust ought to work but does not require a link to an
# open PR.

.if !defined(PLATFORM_SUPPORTS_RUST)

# Rust needs NetBSD>8
.if empty(OS_VERSION:M[0-8].*)
.  for rust_arch in aarch64 earmv7hf i386 powerpc riscv64 sparc64 x86_64
RUST_PLATFORMS+=	NetBSD-*-${rust_arch}
.  endfor
.endif

.for rust_arch in aarch64 earmv7hf i386 x86_64
RUST_PLATFORMS+=	Linux-*-${rust_arch}
.endfor

.for rust_arch in aarch64 x86_64
RUST_PLATFORMS+=	Darwin-*-${rust_arch}
.endfor

RUST_PLATFORMS+=	FreeBSD-*-x86_64
RUST_PLATFORMS+=	SunOS-*-x86_64

.if ${MACHINE_PLATFORM:MNetBSD-*-earm*} && ${OPSYS_VERSION} < 100000
RUST_DIR?=	../../lang/rust176
.endif
RUST_DIR?=	../../lang/rust

.for rust_platform in ${RUST_PLATFORMS}
.  if !empty(MACHINE_PLATFORM:M${rust_platform})
PLATFORM_SUPPORTS_RUST=		yes
.  endif
.endfor
PLATFORM_SUPPORTS_RUST?=	no

.endif # !defined(PLATFORM_SUPPORTS_RUST)
