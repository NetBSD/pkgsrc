# $NetBSD: hacks.mk,v 1.1 2004/12/15 17:13:17 jlam Exp $

### [Wed Dec 15 12:06:48 EST 2004 : jlam]
### On alpha, GCC-2.95.x gives a compiler error when building
### src/ec_inet.c and src/ec_logtofile.c.  Simply require GCC>=3.0 to
### avoid this problem.
###
.if ${MACHINE_ARCH} == "alpha"
PKG_HACKS+=	gcc2-alpha-optimization
GCC_REQD+=	3.0
.endif
