# $NetBSD: platform.mk,v 1.22 2024/03/19 11:18:49 nia Exp $

# This file encodes whether a given platform has support for rust.

.if !defined(PLATFORM_SUPPORTS_RUST)

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} >= 090000
RUST_PLATFORMS+=	NetBSD-*-aarch64
RUST_PLATFORMS+=	NetBSD-*-aarch64eb
RUST_PLATFORMS+=	NetBSD-*-earmv6hf
RUST_PLATFORMS+=	NetBSD-*-earmv7hf
RUST_PLATFORMS+=	NetBSD-*-i386
RUST_PLATFORMS+=	NetBSD-*-mipsel
RUST_PLATFORMS+=	NetBSD-*-powerpc
RUST_PLATFORMS+=	NetBSD-*-riscv64
RUST_PLATFORMS+=	NetBSD-*-sparc64
RUST_PLATFORMS+=	NetBSD-*-x86_64
.endif

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
