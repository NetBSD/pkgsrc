# $NetBSD: hacks.mk,v 1.3 2023/04/19 08:06:31 adam Exp $

.if !defined(ICU_HACKS_MK)
ICU_HACKS_MK=	# defined

# NetBSD arm gcc <= 4.5 missing builtin atomics
.if ${OPSYS} == "NetBSD" && (${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "earm")
.  if ${CC_VERSION:Mgcc-4.[0-5].*}
PKG_HACKS+=	arm-gcc-atomics
CFLAGS+=	-DU_HAVE_GCC_ATOMICS=0
.  endif
.endif

.endif
