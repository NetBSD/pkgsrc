# $NetBSD: hacks.mk,v 1.2 2011/08/15 01:13:25 taca Exp $

.if !defined(RUBY19_BASE_HACKS_MK)
RUBY19_BASE_HACKS_MK=	defined

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
BUILDLINK_TRANSFORM+=	rm:-O[0-9]*
.  endif
.endif

#
# Work around for utimensat(2).
#
.if ${OPSYS} == "NetBSD"
CONFIGURE_ENV+=		ac_cv_func_utimensat=no
.endif

.endif	# RUBY19_BASE_HACKS_MK
