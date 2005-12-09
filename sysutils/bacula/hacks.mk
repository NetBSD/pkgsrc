# $NetBSD: hacks.mk,v 1.3 2005/12/09 19:34:36 tv Exp $

.if !defined(BACULA_HACKS_MK)
BACULA_HACKS_MK=	#defined

### gcc 4.0* has been reported to produce bad code on amd64
### with optimizations (-O2) turned on (causes segfaults).
###
.if ${MACHINE_ARCH} == "amd64"
.  include "../../mk/compiler.mk"
.    if !empty(CC_VERSION:Mgcc-4.0*)
PKG_HACKS+=		dontoptimze
BUILDLINK_TRANSFORM+=	rm:-O[0-9]*
.    endif
.  endif
.endif
