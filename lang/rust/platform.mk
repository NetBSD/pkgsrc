# $NetBSD: platform.mk,v 1.4 2020/06/18 15:00:21 gdt Exp $

# This file encodes whether a given platform has support for rust.

# Platforms where rust ought to work but does not require a link to an
# open PR.

.if !defined(PLATFORM_SUPPORTS_RUST)

# Rust needs NetBSD>7
.  for _rust_arch in aarch64 armv7 i386 powerpc sparc64 x86_64
.    for _rust_os in Darwin FreeBSD Linux NetBSD SunOS
# rust fails to build on NetBSD/earmv7
# http://gnats.netbsd.org/cgi-bin/query-pr-single.pl?number=54621
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
