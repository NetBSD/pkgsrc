# $NetBSD: hacks.mk,v 1.1 2004/11/14 07:24:37 jlam Exp $

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
BUILDLINK_TRANSFORM+=   rm:-O[0-9]*
.endif

.endif	# BISON_HACKS_MK
