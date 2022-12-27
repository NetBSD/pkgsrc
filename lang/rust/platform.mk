# $NetBSD: platform.mk,v 1.17 2022/12/27 18:49:55 nia Exp $

# This file encodes whether a given platform has support for rust.

# Platforms where rust ought to work but does not require a link to an
# open PR.

.if !defined(PLATFORM_SUPPORTS_RUST)

.  include "../../mk/bsd.fast.prefs.mk"

.  if ${OPSYS} == "NetBSD"
.    if ${OPSYS_VERSION} > 090000
RUST_PLATFORMS+=	NetBSD-*-aarch64
RUST_PLATFORMS+=	NetBSD-*-aarch64eb
RUST_PLATFORMS+=	NetBSD-*-earmv6hf
RUST_PLATFORMS+=	NetBSD-*-earmv7hf
RUST_PLATFORMS+=	NetBSD-*-sparc64
.    endif
.    if ${OPSYS_VERSION} > 080000
RUST_PLATFORMS+=	NetBSD-*-i386
RUST_PLATFORMS+=	NetBSD-*-x86_64
RUST_PLATFORMS+=	NetBSD-*-powerpc
.    endif
.  endif

RUST_PLATFORMS+=	Darwin-*-aarch64
RUST_PLATFORMS+=	Darwin-*-x86_64

RUST_PLATFORMS+=	FreeBSD-*-x86_64

RUST_PLATFORMS+=	Linux-*-aarch64
RUST_PLATFORMS+=	Linux-*-earmv6hf
RUST_PLATFORMS+=	Linux-*-earmv7hf
RUST_PLATFORMS+=	Linux-*-i386
RUST_PLATFORMS+=	Linux-*-x86_64

# XXX: how to specifically detect illumos?
.  if ${OPSYS} == "SunOS" && ${OPSYS_VERSION} >= 051000
RUST_PLATFORMS+=	SunOS-*-x86_64
.  endif

.  for rust_platform in ${RUST_PLATFORMS}
.    if !empty(MACHINE_PLATFORM:M${rust_platform})
PLATFORM_SUPPORTS_RUST=		yes
.    endif
.  endfor
PLATFORM_SUPPORTS_RUST?=	no

.endif # !defined(PLATFORM_SUPPORTS_RUST)
