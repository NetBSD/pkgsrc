# $NetBSD: platform.mk,v 1.9 2021/04/23 08:52:12 nia Exp $

# This file encodes whether a given platform has support for rust.

# Platforms where rust ought to work but does not require a link to an
# open PR.

.if !defined(PLATFORM_SUPPORTS_RUST)

.include "../../mk/bsd.fast.prefs.mk"

# Bootstraps built for NetBSD 8.0
.if ${OPSYS} == "NetBSD" && empty(OS_VERSION:M[0-7].*)
RUST_PLATFORMS+=	NetBSD-*-i386
RUST_PLATFORMS+=	NetBSD-*-x86_64
RUST_PLATFORMS+=	NetBSD-*-powerpc
RUST_PLATFORMS+=	NetBSD-*-sparc64
.endif

# Bootstraps built for NetBSD 9.0
.if ${OPSYS} == "NetBSD" && empty(OS_VERSION:M[0-8].*)
RUST_PLATFORMS+=	NetBSD-*-earmv7hf
RUST_PLATFORMS+=	NetBSD-*-aarch64
.endif

RUST_PLATFORMS+=	FreeBSD-*-x86_64
RUST_PLATFORMS+=	Darwin-*-x86_64
RUST_PLATFORMS+=	Linux-*-i386
RUST_PLATFORMS+=	Linux-*-x86_64
RUST_PLATFORMS+=	SunOS-*-x86_64

.  for rust_platform in ${RUST_PLATFORMS}
.    if !empty(MACHINE_PLATFORM:M${rust_platform})
PLATFORM_SUPPORTS_RUST=		yes
.    endif
.  endfor

PLATFORM_SUPPORTS_RUST?=	no

.endif # !defined(PLATFORM_SUPPORTS_RUST)
