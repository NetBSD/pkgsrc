# $NetBSD: hacks.mk,v 1.1 2022/06/22 14:04:49 he Exp $

.if !defined(R_LATER_HACKS_MK)
R_LATER_HACKS_MK=	defined

# On NetBSD/powerpc, use devel/libatomic to get 8-byte atomics.
.if ${MACHINE_ARCH} == "powerpc"
PKG_HACKS+=	powerpc-latomic
.include "../../devel/libatomic/buildlink3.mk"
.endif

.endif	# R_LATER_HACKS_MK
