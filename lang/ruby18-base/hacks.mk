# $NetBSD: hacks.mk,v 1.1 2005/06/06 13:49:25 seb Exp $

.if !defined(RUBY18_BASE_HACKS_MK)
RUBY18_BASE_HACKS_MK=	defined

.include "../../mk/compiler.mk"

### [ Sun Jun  5 10:05:39 CEST 2005 : seb ]
### On NetBSD/sparc64, gcc optimisation, at least for version 3.3.3,
### produces segmentation faulting miniruby binary.
### Also note that `-O' level optimisation produces a miniruby
### binary that loops while running the installation scripts.
###
.if !empty(MACHINE_PLATFORM:MNetBSD-*-sparc64)
.  if !empty(CC_VERSION:Mgcc-3.3.*)
PKG_HACKS+=		optimisation
BUILDLINK_TRANSFORM+=   rm:-O[0-9]*
.  endif
.endif

.endif	# RUBY18_BASE_HACKS_MK
