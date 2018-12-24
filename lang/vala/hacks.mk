# $NetBSD: hacks.mk,v 1.1 2018/12/24 00:10:09 tsutsui Exp $

.if !defined(VALA_HACKS_MK)
VALA_HACKS_MK=	defined

.include "../../mk/compiler.mk"

### On NetBSD/earmv6hf 8.0 with gcc 5.5.0, vala binaries compiled with the
### default optiomization options produce segmentation faulting.
### Compiling with `-fno-optimize-sibling-calls' works around.
###
.if !empty(MACHINE_PLATFORM:MNetBSD-*-*arm*) && !empty(CC_VERSION:Mgcc-5.*)
PKG_HACKS+=	optimisation
CFLAGS+=	-fno-optimize-sibling-calls
.endif

.endif	# VALA_HACKS_MK
