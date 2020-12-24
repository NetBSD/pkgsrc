# $NetBSD: hacks.mk,v 1.1 2020/12/24 20:29:14 yhardy Exp $

.if !defined(QPDF_HACKS_MK)
QPDF_HACKS_MK=	defined

# [Tue Dec 15 15:49:14 SAST 2020 : yhardy]
# On i386 archs libqpdf/QPDF.cc fails to compile because 64-bit atomic
# operations are needed.  Forcing -march=i586 (or better) avoids that
# (i[56]86 provide required).
.if ${MACHINE_ARCH} == "i386"
PKG_HACKS+=	i386-atomicops
CXXFLAGS+=	-march=i586
.endif

# [Tue Dec 15 15:49:14 SAST 2020 : yhardy]
# On NetBSD/powerpc, we don't have native 8-byte atomics, but qpdf
# needs it for a global long long counter, so here we need libatomic.
.if ${MACHINE_ARCH} == "powerpc"
PKG_HACKS+=     powerpc-libatomic
.include "../../devel/libatomic/buildlink3.mk"
.endif

.endif	# QPDF_HACKS_MK
