# $NetBSD: hacks.mk,v 1.1 2022/08/05 14:34:12 he Exp $

.if !defined(NET_LIBFILEZILLA_HACKS_MK)
NET_LIBFILEZILLA_HACKS_MK=  defined

# [Fri Aug  5 14:57:31 CEST 2022 : he]

# On NetBSD/powerpc, use devel/libatomic to get 8-byte atomics.
.if ${MACHINE_ARCH} == "powerpc" && ${OPSYS} == "NetBSD"
PKG_HACKS+=     powerpc-atomics
.include "../../devel/libatomic/buildlink3.mk"
.endif

.endif  # NET_LIBFILEZILLA_HACKS_MK
