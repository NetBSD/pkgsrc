# $NetBSD: hacks.mk,v 1.3 2014/01/06 11:16:23 martin Exp $

### [Sun Jan  5 12:58:28 UTC 2014 : tron]
### GCC 4.5.3 gets stuck while compiline "vp9/vp9_cx_iface.c".
### See PR port-sparc64/48501 for more details.
.if !empty(MACHINE_PLATFORM:MNetBSD-*-sparc64)
.  include "../../mk/compiler.mk"
.  if !empty(CC_VERSION:Mgcc-4.[0-5].*)
PKG_HACKS+=		sparc64-gcc-lock-up
BUILDLINK_TRANSFORM+=	rm:-O[0-9]*
.  endif
.endif
