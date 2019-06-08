# $NetBSD: hacks.mk,v 1.2 2019/06/08 10:40:54 rillig Exp $

.if !defined(EMACS_HACKS_MK)
EMACS_HACKS_MK=	defined

.include "../../mk/compiler.mk"

### On NetBSD/amd64 7.99.27, gcc optimisation, at least for version 5.3,
### produces, a "temacs" binary which segfaults.
###
.if !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64)
.  if !empty(CC_VERSION:Mgcc-5.3.*)
PKG_HACKS+=		optimisation
BUILDLINK_TRANSFORM+=	opt:-O2:-O0
.  endif
.endif

.endif  # EMACS_HACKS_MK
