# $NetBSD: platform.mk,v 1.30 2025/02/23 08:53:54 he Exp $

# This file encodes whether a given platform has support for rust.

# Platforms where rust ought to work but does not require a link to an
# open PR.

.if !defined(PLATFORM_SUPPORTS_RUST)

# Rust needs NetBSD>=9.0
# (and really wants the ld.elf_so fixes from later netbsd-9-based releases)
.for rust_arch in aarch64 earmv7hf i386 powerpc riscv64 sparc64 x86_64
.  for rust_os in Darwin FreeBSD Linux NetBSD SunOS
.    if ${OPSYS} != "NetBSD" || empty(OS_VERSION:M[0-8].*)
RUST_PLATFORMS+=	${rust_os}-*-${rust_arch}
.    endif
.  endfor
.endfor

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
