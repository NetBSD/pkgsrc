# $NetBSD: hacks.mk,v 1.1 2022/07/24 20:33:49 he Exp $

.if !defined(NET_DHCPD4_HACKS_MK)
NET_DHCPD4_HACKS_MK=	defined

# [Sun Jul 24 20:23:03 CEST 2022 : he]
# On NetBSD/powerpc, use devel/libatomic to get 8-byte atomics.
.if ${MACHINE_ARCH} == "powerpc" && ${OPSYS} == "NetBSD"
PKG_HACKS+=	powerpc-atomics
.include "../../devel/libatomic/buildlink3.mk"
.endif

.endif	# NET_DHCPD4_HACKS_MK
