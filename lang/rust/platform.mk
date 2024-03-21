# $NetBSD: platform.mk,v 1.23 2024/03/21 02:14:14 nia Exp $

# This file encodes whether a given platform has support for rust.

.if !defined(PLATFORM_SUPPORTS_RUST)

.include "../../mk/bsd.fast.prefs.mk"

# Little bit of future-proofing.
.for i in 9 10 11
RUST_PLATFORMS+=	NetBSD-${i}.*-aarch64
RUST_PLATFORMS+=	NetBSD-${i}.*-aarch64eb
RUST_PLATFORMS+=	NetBSD-${i}.*-earmv6hf
RUST_PLATFORMS+=	NetBSD-${i}.*-earmv7hf
RUST_PLATFORMS+=	NetBSD-${i}.*-i386
RUST_PLATFORMS+=	NetBSD-${i}.*-mipsel
RUST_PLATFORMS+=	NetBSD-${i}.*-powerpc
RUST_PLATFORMS+=	NetBSD-${i}.*-riscv64
RUST_PLATFORMS+=	NetBSD-${i}.*-sparc64
RUST_PLATFORMS+=	NetBSD-${i}.*-x86_64
.endfor

RUST_PLATFORMS+=	Darwin-*-aarch64
RUST_PLATFORMS+=	Darwin-*-x86_64
RUST_PLATFORMS+=	FreeBSD-*-x86_64
RUST_PLATFORMS+=	Linux-*-aarch64
RUST_PLATFORMS+=	Linux-*-earmv6hf
RUST_PLATFORMS+=	Linux-*-earmv7hf
RUST_PLATFORMS+=	Linux-*-i386
RUST_PLATFORMS+=	Linux-*-x86_64
RUST_PLATFORMS+=	SunOS-*-x86_64

.for rust_platform in ${RUST_PLATFORMS}
.  if !empty(MACHINE_PLATFORM:M${rust_platform})
PLATFORM_SUPPORTS_RUST=		yes
.  endif
.endfor
PLATFORM_SUPPORTS_RUST?=	no

.endif # !defined(PLATFORM_SUPPORTS_RUST)
