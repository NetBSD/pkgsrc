# $NetBSD: platform.mk,v 1.14 2022/04/30 21:02:39 nia Exp $

# This file encodes whether a given platform has support for rust.

# Platforms where rust ought to work but does not require a link to an
# open PR.

.if !defined(PLATFORM_SUPPORTS_RUST)

.  include "../../mk/bsd.fast.prefs.mk"

.  for rust_arch in aarch64 earmv7hf i386 powerpc sparc64 x86_64
.    for rust_os in Darwin FreeBSD Linux NetBSD SunOS
RUST_PLATFORMS+=	${rust_os}-*-${rust_arch}
.    endfor
.  endfor

.  if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 080000
PLATFORM_SUPPORTS_RUST?=	no
.  else
.    for rust_platform in ${RUST_PLATFORMS}
.      if !empty(MACHINE_PLATFORM:M${rust_platform})
PLATFORM_SUPPORTS_RUST=		yes
.      endif
.    endfor
PLATFORM_SUPPORTS_RUST?=	no
.  endif

.endif # !defined(PLATFORM_SUPPORTS_RUST)
