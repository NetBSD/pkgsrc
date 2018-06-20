# $NetBSD: hacks.mk,v 1.1 2018/06/20 11:04:19 mef Exp $

.if !defined(EMACS_HACKS_MK)
EMACS_HACKS_MK=	defined

.include "../../mk/compiler.mk"

### On NetBSD/amd64 7.99.26, gcc optimisation, at least for version 5.x,
### produces, a "temacs" binary which segfaults.
###
.if !empty(MACHINE_PLATFORM:MNetBSD-*)
.  if !empty(CC_VERSION:Mgcc-5.*)
PKG_HACKS+=		optimisation
CFLAGS+=		-fno-optimize-strlen
.  endif
.endif

.endif  # EMACS_HACKS_MK
