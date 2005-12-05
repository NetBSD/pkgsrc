# $NetBSD: hacks.mk,v 1.2 2005/12/05 20:51:03 rillig Exp $

.if !defined(JADE_HACKS_MK)
JADE_HACKS_MK=		# defined

### [Tue Jan 25 20:25:41 UTC 2005 : tv]
### Interix system-supplied g++ 3.3 is generating broken global ctors/dtors
###
.if ${OPSYS} == "Interix"
PKG_HACKS+=		g++-broken-globals
GCC_REQD+=		3.3.4
.endif

.endif
