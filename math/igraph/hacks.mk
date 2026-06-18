# $NetBSD: hacks.mk,v 1.1 2026/06/18 15:06:18 nia Exp $

.if !defined(IGRAPH_HACKS_MK)
IGRAPH_HACKS_MK=	# defined

### [Thu Jun 18 17:04:43 CEST 2026 : nia]
### NetBSD 9.x does not expose all standard C++ functions with default
### source visibility.
###
.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 100000
PKG_HACKS+=		netbsd-source
CXXFLAGS+=		-D_NETBSD_SOURCE
.endif

.endif
