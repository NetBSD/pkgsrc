# $NetBSD: atomic64.mk,v 1.7 2022/11/15 17:14:48 he Exp $
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

.if ${MACHINE_ARCH} == "m68k" || \
    ${MACHINE_ARCH} == "mipsel" || \
    ${MACHINE_ARCH} == "mipseb" || \
    ${MACHINE_ARCH} == "powerpc" || \
    ${MACHINE_ARCH} == "sparc" || \
    ${MACHINE_ARCH} == "vax"
.  include "../../devel/libatomic/buildlink3.mk"
.endif

.endif
