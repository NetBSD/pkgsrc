# $NetBSD: hacks.mk,v 1.1 2005/01/24 20:48:05 tv Exp $

.ifndef NETPBM_HACKS_MK
NETPBM_HACKS_MK=	# defined

### [historic : ???]
### gcc optimization fixes
###
.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
PKG_HACKS+=		optimization
GCC_REQD+=		2.95.3
.endif
.if ${MACHINE_ARCH} == "alpha"
PKG_HACKS+=		optimization
GCC_REQD+=		3.0
.endif

### [Mon Jan 24 20:47:14 UTC 2005 : tv]
### substitute for <inttypes.h> on Interix
###
.if ${OPSYS} == "Interix"
PKG_HACKS+=		standard-headers
MAKE_FLAGS+=		INTTYPES_H='<sys/types.h>'
.endif

.endif
