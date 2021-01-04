# $NetBSD: platform.mk,v 1.7 2021/01/04 11:25:27 nia Exp $

# This file encodes whether a given platform has support for rust.

# Platforms where rust ought to work but does not require a link to an
# open PR.

.if !defined(PLATFORM_SUPPORTS_RUST)

.include "../../mk/bsd.fast.prefs.mk"

# All Rust bootstraps are built for NetBSD 8.0 at minimum.
.  if !empty(MACHINE_PLATFORM:MNetBSD-7.*-*)
PLATFORM_SUPPORTS_RUST?=	no
.  endif

# Rust bootstraps are built for NetBSD 9.0 on the following platforms.
.  if !empty(MACHINE_PLATFORM:MNetBSD-8.*-*arm*) || \
      !empty(MACHINE_PLATFORM:MNetBSD-8.*-aarch64*) || \
      !empty(MACHINE_PLATFORM:MNetBSD-8.*-sparc64)
PLATFORM_SUPPORTS_RUST?=	no
.  endif

RUST_PLATFORMS+=	Darwin-*-x86_64
RUST_PLATFORMS+=	FreeBSD-*-i386
RUST_PLATFORMS+=	FreeBSD-*-x86_64
RUST_PLATFORMS+=	Linux-*-i386
RUST_PLATFORMS+=	Linux-*-x86_64
RUST_PLATFORMS+=	NetBSD-*-i386
RUST_PLATFORMS+=	NetBSD-*-x86_64
RUST_PLATFORMS+=	NetBSD-*-powerpc
RUST_PLATFORMS+=	NetBSD-*-aarch64
RUST_PLATFORMS+=	NetBSD-*-sparc64
RUST_PLATFORMS+=	NetBSD-*-earmv7hf
RUST_PLATFORMS+=	SunOS-*-x86_64

.  for rust_platform in ${RUST_PLATFORMS}
.    if !empty(MACHINE_PLATFORM:M${rust_platform})
PLATFORM_SUPPORTS_RUST?=	yes
.    endif
.  endfor
PLATFORM_SUPPORTS_RUST?=	no

.endif # !defined(PLATFORM_SUPPORTS_RUST)
