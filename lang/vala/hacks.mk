# $NetBSD: hacks.mk,v 1.3 2023/04/09 07:11:50 wiz Exp $

.if !defined(VALA_HACKS_MK)
VALA_HACKS_MK=	defined

.include "../../mk/compiler.mk"

### On NetBSD/earmv6hf 8.0 with gcc 5.5.0 and 8.99.25 with gcc 6.5.0,
### vala binaries compiled with the default optiomization options produce
### segmentation faulting.
### Compiling with `-fno-optimize-sibling-calls' works around.
###
.if ${MACHINE_PLATFORM:MNetBSD-*-*arm*} && ${CC_VERSION:Mgcc-[56].*}
PKG_HACKS+=	optimisation
CFLAGS+=	-fno-optimize-sibling-calls
.endif

.endif	# VALA_HACKS_MK
