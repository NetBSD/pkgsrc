# $NetBSD: atomic64.mk,v 1.1 2020/12/31 20:04:12 nia Exp $
#
# This Makefile fragment is included by packages that require 64-bit atomic
# operations, and will attempt to set the appropriate architecture-specific
# compiler flags.

.if !defined(ATOMIC64_MK)

ATOMIC64_MK:=

.include "../../bsd.fast.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
.  if empty(CFLAGS:M*march=*)
CFLAGS+=	-march=i586
CXXFLAGS+=	-march=i586
.  endif
.endif

.if ${MACHINE_ARCH} == "powerpc"
.  include "../../devel/libatomic/buildlink3.mk"
.endif

.endif
