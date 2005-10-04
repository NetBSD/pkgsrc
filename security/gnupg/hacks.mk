# $NetBS$

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
