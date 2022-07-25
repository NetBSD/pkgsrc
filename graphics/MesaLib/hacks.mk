# $NetBSD: hacks.mk,v 1.15 2022/07/25 09:49:06 he Exp $

.if !defined(GRAPHICS_MESALIB_HACKS_MK)
GRAPHICS_MESALIB__HACKS_MK=	defined

# [Sun Jul 24 20:23:03 CEST 2022 : he]
# On NetBSD/powerpc, use devel/libatomic to get 8-byte atomics.
.if ${MACHINE_ARCH} == "powerpc" && ${OPSYS} == "NetBSD"
PKG_HACKS+=	powerpc-atomics
.include "../../devel/libatomic/buildlink3.mk"
.endif

.endif	# GRAPHICS_MESALIB_HACKS_MK
