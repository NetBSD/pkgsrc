# $NetBSD: hacks.mk,v 1.1 2014/01/05 13:27:10 tron Exp $

### [Sun Jan  5 12:58:28 UTC 2014 : tron]
### GCC 4.5.3 gets stuck while compiline "vp9/vp9_cx_iface.c".
###
.if !empty(MACHINE_PLATFORM:MNetBSD-*-sparc64)
.  include "../../mk/compiler.mk"
.  if !empty(CC_VERSION:Mgcc*)
PKG_HACKS+=		sparc64-gcc-lock-up
BUILDLINK_TRANSFORM+=	rm:-O[0-9]*
.  endif
.endif
