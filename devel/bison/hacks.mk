# $NetBSD: hacks.mk,v 1.2 2007/02/22 19:26:20 wiz Exp $

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

.endif	# BISON_HACKS_MK
