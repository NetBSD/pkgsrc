# $NetBSD: hacks.mk,v 1.1 2006/07/26 20:00:27 jlam Exp $

.include "../../mk/compiler.mk"

### [Thu Jan 23 01:28:36 2003 UTC : dmcmahill]
### On PowerPC, building with optimisation with GCC causes an "attempt
### to free unreference scalar".  Remove optimisation flags as a
### workaround until GCC is fixed.
###
.if !empty(CC_VERSION:Mgcc*) && !empty(MACHINE_PLATFORM:MNetBSD-*-alpha)
PKG_HACKS+=		alpha-codegen
BUILDLINK_TRANSFORM+=	rename:-O[0-9]*:-O
.endif
