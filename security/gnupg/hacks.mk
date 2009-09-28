# $NetBSD: hacks.mk,v 1.5 2009/09/28 20:15:08 tnn Exp $

.if !defined(GNUPG_HACKS_MK)
GNUPG_HACKS_MK=	# defined

### workaround for a GCC optimizer bug on sparc:
### drop any -mcpu flag
###
.if ${MACHINE_ARCH} == "sparc"
PKG_HACKS+=		mcpu
BUILDLINK_TRANSFORM+=	rm:-mcpu=.*
.endif

# Turn off optimization in CFLAGS for AIX. Otherwise
# decryption fails with, "Rijndael-128 test encryption failed."
# at runtime.
.if ${OPSYS} == "AIX"
PKG_HACKS+=	aix-codegen
CFLAGS:=	-O0 ${CFLAGS:C/-O[0-9]?//g}
.endif

.endif
