# $NetBSD: hacks.mk,v 1.5.2.2 2020/09/18 18:22:54 bsiegert Exp $

.if !defined(GROONGA_HACKS_MK)
GROONGA_HACKS_MK=	defined

# [Mon Sep  7 20:40:36 CEST 2020 : he]
# On NetBSD/powerpc, we don't have native 8-byte atomics,
# but this package insists on using them, so here we need libatomic.
.if ${MACHINE_ARCH} == "powerpc"
PKG_HACKS+=     powerpc-libatomic
.include "../../devel/libatomic/buildlink3.mk"
.endif

.endif	# GROONGA_HACKS_MK
