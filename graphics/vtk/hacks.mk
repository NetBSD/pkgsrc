# $NetBSD: hacks.mk,v 1.1 2022/07/29 09:56:49 he Exp $

.if !defined(GRAPHICS_VTK_HACKS_MK)
GRAPHICS_VTK__HACKS_MK=	defined

# [Fri Jul 29 11:55:42 CEST 2022 : he ]
# On NetBSD/powerpc, use devel/libatomic to get 8-byte atomics.
.if ${MACHINE_ARCH} == "powerpc" && ${OPSYS} == "NetBSD"
PKG_HACKS+=	powerpc-atomics
.include "../../devel/libatomic/buildlink3.mk"
.endif

.endif	# GRAPHICS_VTK_HACKS_MK
