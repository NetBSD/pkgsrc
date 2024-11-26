# $NetBSD: hacks.mk,v 1.3 2024/11/26 12:35:44 nia Exp $

.if !defined(NODEJS_HACKS_MK)
NODEJS_HACKS_MK=		# defined

### [Mon May 27 10:49:39 CEST 2024 : nia]
### NetBSD 9.x does not expose all standard C++ functions with default
### source visibility.
###
.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 100000
PKG_HACKS+=	netbsd-source
CXXFLAGS+=	-D_NETBSD_SOURCE
.endif

### [Tue Nov 26 13:34:51 CET 2024]
### NetBSD 9.x lacks a definition for DT_GNU_HASH.
###
.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 100000
PKG_HACKS+=	netbsd-gnu-hash
CXXFLAGS+=	-DDT_GNU_HASH=0x6ffffef5
.endif

.endif
