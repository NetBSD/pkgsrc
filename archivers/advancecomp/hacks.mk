# $NetBSD: hacks.mk,v 1.1 2005/01/21 21:48:32 tv Exp $

.ifndef ADVANCECOMP_HACKS_MK
ADVANCECOMP_HACKS_MK=	# defined

### [Fri Jan 21 21:44:32 UTC 2005 : tv]
### Interix system-supplied g++ 3.3 iostream has no "long long" support
###
.if ${OPSYS} == "Interix"
PKG_HACKS+=		g++-iostream-longlong
GCC_REQD+=		3.3.4
.endif

.endif
