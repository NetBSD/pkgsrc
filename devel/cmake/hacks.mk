# $NetBSD: hacks.mk,v 1.1.2.2 2026/11/11 09:06:54 maya Exp $

.if !defined(CMAKE_HACKS_MK)
CMAKE_HACKS_MK=	defined

.include "../../mk/compiler.mk"

# On NetBSD/m68k, GCC 14 optimisation produces segmentation faulting
# cmake binary. See PR toolchain/60970 for more details.
.if ${MACHINE_PLATFORM:MNetBSD-*-m68k} && ${CC_VERSION:Mgcc-1[4-9].*}
PKG_HACKS+=		optimisation
BUILDLINK_TRANSFORM+=	opt:-O2:-Os
.endif

.endif	# CMAKE_HACKS_MK
