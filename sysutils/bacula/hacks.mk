# $NetBSD: hacks.mk,v 1.1 2005/11/22 18:35:25 wiz Exp $

.ifndef BACULA_HACKS_MK
BACULA_HACKS_MK=	#defined

### gcc 4.0* has been reported to produce bad code on amd64
### with optimizations (-O2) turned on (causes segfaults).
###
.if ${MACHINE_ARCH} == "amd64"

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-4.0*)
PKG_HACKS+=		dontoptimze
BUILDLINK_TRANSFORM+=	rm:-O[0-9]*
.endif

.endif

.endif
