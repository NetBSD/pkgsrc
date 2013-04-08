# $NetBSD: hacks.mk,v 1.2 2013/04/08 11:17:12 rodent Exp $

.if !defined(XEMACS_HACKS_MK)
XEMACS_HACKS_MK=	defined

.include "../../mk/compiler.mk"

### [Sun Dec 10 10:00:00 UTC 2011 : hauke]
### On PowerPC, building with -O2 optimisation with GCC (on netbsd-5,
### at least) results in 'xemacs -vanilla' dumping core.
### Lower optimisation as a workaround, until GCC is fixed.
###
.if !empty(CC_VERSION:Mgcc*) && !empty(MACHINE_PLATFORM:MNetBSD-*-powerpc)
PKG_HACKS+=		powerpc-codegen
BUILDLINK_TRANSFORM+=	rename:-O[0-9]*:-Os
.endif

.endif  # XEMACS_HACKS_MK
