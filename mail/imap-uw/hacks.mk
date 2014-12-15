# $NetBSD: hacks.mk,v 1.2 2014/12/15 11:46:35 jperkin Exp $

.include "../../mk/compiler.mk"

### [Thu Jan 23 01:28:36 2003 UTC : dmcmahill]
### On PowerPC, building with optimisation with GCC causes an "attempt
### to free unreference scalar".  Remove optimisation flags as a
### workaround until GCC is fixed.
###
.if !empty(CC_VERSION:Mgcc*) && !empty(MACHINE_PLATFORM:MNetBSD-*-alpha)
PKG_HACKS+=		alpha-codegen
BUILDLINK_TRANSFORM+=	opt:-O[0-9]*:-O
.endif
