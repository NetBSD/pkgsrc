# $NetBSD: hacks.mk,v 1.4 2014/05/26 18:10:22 tron Exp $

### [Sun Jan  5 12:58:28 UTC 2014 : tron]
### GCC 4.5.3 gets stuck while compiline "vp9/vp9_cx_iface.c".
### See PR port-sparc64/48501 for more details.
.if !empty(MACHINE_PLATFORM:MNetBSD-*-sparc*)
.  include "../../mk/compiler.mk"
.  if !empty(CC_VERSION:Mgcc-4.[0-5].*)
PKG_HACKS+=		sparc-gcc-lock-up
BUILDLINK_TRANSFORM+=	rm:-O[0-9]*
.  endif
.endif
