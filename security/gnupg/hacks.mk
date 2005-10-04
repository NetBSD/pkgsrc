# $NetBSD: hacks.mk,v 1.2 2005/10/04 22:50:41 wiz Exp $

.ifndef GNUPG_HACKS_MK
GNUPG_HACKS_MK=         #defined

### workaround for a GCC optimizer bug on sparc:
### drop any -mcpu flag
###
.if ${MACHINE_ARCH} == "sparc"
PKG_HACKS+=             mcpu
BUILDLINK_TRANSFORM+=   rm:-mcpu=.*
.endif

.endif
