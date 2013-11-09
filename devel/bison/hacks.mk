# $NetBSD: hacks.mk,v 1.5 2013/11/09 05:32:46 ryoon Exp $

.if !defined(BISON_HACKS_MK)
BISON_HACKS_MK=	defined

.include "../../mk/compiler.mk"

### [Tue Nov  2 17:30:48 GMT 2004 : sketch]
### bison's quotearg_buffer_restyled() has issues with certain compilers
### (in particular, SunPro on Solaris/sparc) using optimisation flags.
### The resulting bison with optimisation breaks on at least net/libIDL.
###
.if !empty(PKGSRC_COMPILER:Msunpro)
PKG_HACKS+=		optimisation
BUILDLINK_TRANSFORM+=	rm:-O[0-9]*
.endif

### gcc-4.5.3 in NetBSD/arm 5.99.59 also breaks bison in net/libIDL.
### -O seems enough for workaround in this case.
.if !empty(MACHINE_PLATFORM:MNetBSD-*-*arm*) && !empty(CC_VERSION:Mgcc-4.5.*)
PKG_HACKS+=		optimisation
BUILDLINK_TRANSFORM+=	rename:-O[0-9]*:-O
.endif

.endif	# BISON_HACKS_MK
