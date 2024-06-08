# $NetBSD: hacks.mk,v 1.1 2024/06/08 08:05:14 nia Exp $

.if !defined(BAZEL_HACKS_MK)
BAZEL_HACKS_MK=		# defined

### [Sat Jun  8 09:59:16 CEST 2024 : nia]
### NetBSD 9.x does not expose all standard C++ functions with default
### source visibility.
###
.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 100000
PKG_HACKS+=		netbsd-source
CXXFLAGS+=		-D_NETBSD_SOURCE
.endif

.endif
