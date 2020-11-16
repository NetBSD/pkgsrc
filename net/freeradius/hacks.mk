# $NetBSD: hacks.mk,v 1.2 2020/11/16 11:57:19 nia Exp $

.if !defined(FREERADIUS_HACKS_MK)
FREERADIUS_HACKS_MK=	defined

# [Mon Sep  7 20:40:36 CEST 2020 : he]
# On NetBSD/powerpc, we don't have native 8-byte atomics,
# but this package insists on using them, so here we need libatomic.
.if ${MACHINE_ARCH} == "powerpc"
PKG_HACKS+=     powerpc-libatomic
.include "../../devel/libatomic/buildlink3.mk"
.endif

.if ${MACHINE_ARCH} == "i386"
PKG_HACKS+=	i386-atomics
CFLAGS+=	-march=i586
.endif

.endif	# FREERADIUS_HACKS_MK
