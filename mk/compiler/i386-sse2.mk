# $NetBSD: i386-sse2.mk,v 1.1 2025/04/08 00:22:34 gdt Exp $
#
# This Makefile fragment is included by packages that require SSE2
# instructions on i386 processors.  If on i386, it will add flags
# instructing various compilers (that the package might or might not
# use) that they may emit SSE2 instructions.
#
# The point is to enable programs which cannot be built or cannot be
# reasonably be built without SSE2 to build, while not changing the
# base machine definition (and thus causing i386 binaries in general
# to fail on pre-SSE2 hardware.

# i485 and i586 (pentium) never have SSE2.
# i686 means "Pentium Pro" instruction set, with no SSE2.
# Within i686, Pentium II and Pentium III also lack SSE2.
# Pentium M, 4, 4-M, and essentially all later CPUs have SSE2.

# When enabling SSE2, we enable generation of the i686 instruction set
# when convenient, because no pre-686 processors implement SSE2, so
# there's no portability gain from leaving the increased efficiency on
# the table.

.if !defined(I386_SSE2_MK)

I386_SSE2_MK:=

.include "../../mk/bsd.fast.prefs.mk"

.if ${MACHINE_ARCH} == "i386"

.  if empty(CFLAGS:M*sse2=*)
CFLAGS+=	-march=i686 -msse2
.  endif

# rust defaults to i586.  Choose minimal enabling of sse2, at least
# for now.
RUSTFLAGS+=	-C target-feature=+sse2

.endif

.endif
