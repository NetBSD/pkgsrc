# $NetBSD: hacks.mk,v 1.3 2005/12/05 20:50:56 rillig Exp $

.if !defined(GNUPG_HACKS_MK)
GNUPG_HACKS_MK=	# defined

### workaround for a GCC optimizer bug on sparc:
### drop any -mcpu flag
###
.if ${MACHINE_ARCH} == "sparc"
PKG_HACKS+=             mcpu
BUILDLINK_TRANSFORM+=   rm:-mcpu=.*
.endif

.endif
