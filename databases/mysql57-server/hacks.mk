# $NetBSD: hacks.mk,v 1.1 2020/09/22 22:18:55 he Exp $

.if !defined(MYSQL_HACKS_MK)
MYSQL_HACKS_MK=	defined

# [Tue Sep 22 21:38:02 CEST 2020 : he]
# On NetBSD/powerpc, use devel/libatomic to get 8-byte atomics.
.if ${MACHINE_ARCH} == "powerpc"
.include "../../devel/libatomic/buildlink3.mk"
.endif

.endif	# MYSQL_HACKS_MK
