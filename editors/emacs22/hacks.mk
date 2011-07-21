# $NetBSD: hacks.mk,v 1.6 2011/07/21 01:37:19 tron Exp $

.if !defined(EMACS_HACKS_MK)
EMACS_HACKS_MK=	defined

.include "../../mk/compiler.mk"

### [ Wed Jul 20 23:40:49 UTC 2011 : tron ]
### On NetBSD/i386, gcc optimisation, at least for version 4.5.3, produces
### a "temacs" binary which segfaults.
###
.  if !empty(MACHINE_PLATFORM:MNetBSD-*-i386)
.    if !empty(CC_VERSION:Mgcc-4.5.*)
PKG_HACKS+=		optimisation
BUILDLINK_TRANSFORM+=	rename:-O[0-9]*:-O0
.    endif
.  endif

###
### Workaround for PR pkg/39778
###
.  if !empty(MACHINE_PLATFORM:MNetBSD-[4-9].*-x86_64)
pre-build:
	${TOUCH} ${WRKSRC}/leim/quail/tsang-b5.el
.  endif

.endif  # EMACS_HACKS_MK
