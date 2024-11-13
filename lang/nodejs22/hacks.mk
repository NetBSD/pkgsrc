# $NetBSD: hacks.mk,v 1.1 2024/11/13 08:45:17 adam Exp $

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

.endif
