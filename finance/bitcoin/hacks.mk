# $NetBSD: hacks.mk,v 1.1 2022/08/01 18:14:25 he Exp $

.if !defined(FINANCE_BITCOIN_HACKS_MK)
FINANCE_BITCOIN__HACKS_MK=	defined

# [ Mon Aug  1 13:09:11 CEST 2022 : he ]
# On NetBSD/powerpc, use devel/libatomic to get 8-byte atomics.
.if ${MACHINE_ARCH} == "powerpc" && ${OPSYS} == "NetBSD"
PKG_HACKS+=	powerpc-atomics
.include "../../devel/libatomic/buildlink3.mk"
.endif

.endif	# FINANCE_BITCOIN_HACKS_MK
