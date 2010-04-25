# $NetBSD: hacks.mk,v 1.1.1.1 2010/04/25 12:46:19 obache Exp $

.if !defined(PSTOTEXT_HACKS_MK)
PSTOTEXT_HACKS_MK=	defined

.include "../../mk/compiler.mk"

###
### With debian's security patch patch-ab, pstotext miscompiles under several
### versions of gcc-4.x when -O2 is used. It compiles fine with the
### -fno-strict-aliasing option.
### For the time being, pstotext will be compiled with -fno-strict-aliasing
### on any platform when gcc-4 is used independent of the compiler options.
###
.if !empty(CC_VERSION:Mgcc-4.*)
PKG_HACKS+=		optimisation
CFLAGS+=		-fno-strict-aliasing # must come at the end of CFLAGs.
.endif

.endif  # PSTOTEXT_HACKS_MK
