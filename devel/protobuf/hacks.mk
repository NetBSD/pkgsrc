# $NetBSD: hacks.mk,v 1.1.2.2 2020/09/18 18:20:57 bsiegert Exp $

.if !defined(PROTOBUF_HACKS_MK)
PROTOBUF_HACKS_MK=	defined

# [ Tue Sep  8 08:38:08 CEST 2020 : he ]
# Bring -latomic into scope; build insists on it being available
# on this platform (probably due to no native 8-byte atomics).
.if !empty(MACHINE_ARCH:Mpowerpc*)
.include "../../devel/libatomic/buildlink3.mk"
PKG_HACKS+=	powerpc-libatomic
.endif

.endif	# PROTOBUF_HACKS_MK
