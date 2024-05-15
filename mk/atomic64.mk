# $NetBSD: atomic64.mk,v 1.9 2024/05/15 07:37:46 nia Exp $
#
# This Makefile fragment is included by packages that require 64-bit atomic
# operations, and will attempt to set the appropriate architecture-specific
# compiler flags.

.if !defined(ATOMIC64_MK)

ATOMIC64_MK:=

.include "../../mk/bsd.fast.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
.  if empty(CFLAGS:M*march=*)
CFLAGS+=	-march=i586
.  endif
.endif

# Non-NetBSD vendors tend to include libatomic as part of gcc.
.if ${OPSYS} == "NetBSD" && \
    (${MACHINE_ARCH} == "m68k" || \
    ${MACHINE_ARCH} == "mipsel" || \
    ${MACHINE_ARCH} == "mipseb" || \
    ${MACHINE_ARCH} == "powerpc" || \
    ${MACHINE_ARCH} == "sparc" || \
    ${MACHINE_ARCH} == "vax" || \
    !empty(MACHINE_ARCH:Mearm*))
.  include "../../devel/libatomic/buildlink3.mk"
.endif

.endif
