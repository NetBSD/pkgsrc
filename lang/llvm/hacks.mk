# $NetBSD: hacks.mk,v 1.1 2020/09/20 09:37:17 he Exp $

.if !defined(LLVM_HACKS_MK)
LLVM_HACKS_MK=	defined

# [Sun Sep 20 11:08:39 CEST 2020 : he]
# On NetBSD/powerpc, use devel/libatomic to get 8-byte atomics.
.if ${MACHINE_ARCH} == "powerpc"
.include "../../devel/libatomic/buildlink3.mk"
.endif

.endif	# LLVM_HACKS_MK
