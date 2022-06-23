# $NetBSD: hacks.mk,v 1.1 2022/06/23 13:57:35 he Exp $

.if !defined(PROTOC_C_HACKS_MK)
PROTOC_C_HACKS_MK=	defined

# [Wed Jun 22 17:05:22 CEST 2022 : he]
# On NetBSD/powerpc, use devel/libatomic to get 8-byte atomics.
.if ${MACHINE_ARCH} == "powerpc" && ${OPSYS} == "NetBSD"
PKG_HACKS+=	powerpc-atomics
.include "../../devel/libatomic/buildlink3.mk"
.endif

.endif	# PROTOC_C_HACKS_MK
