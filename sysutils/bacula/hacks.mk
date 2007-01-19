# $NetBSD: hacks.mk,v 1.5 2007/01/19 11:38:33 ghen Exp $

.if !defined(BACULA_HACKS_MK)
BACULA_HACKS_MK=	#defined

### gcc 4.0* has been reported to produce bad code on amd64
### with optimizations (-O2) turned on (causes segfaults).
###
.if ${MACHINE_ARCH} == "amd64" || ${MACHINE_ARCH} == "alpha" || ${MACHINE_ARCH} == "sparc64"
.  include "../../mk/compiler.mk"
.  if !empty(CC_VERSION:Mgcc-4.0*)
PKG_HACKS+=		dontoptimze
BUILDLINK_TRANSFORM+=	rm:-O[0-9]*
.  endif
.endif
.endif
