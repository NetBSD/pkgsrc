# $NetBSD: hacks.mk,v 1.6 2023/04/23 14:03:08 adam Exp $

.if !defined(BOOST_LIBS_HACKS_MK)
BOOST_LIBS_HACKS_MK=	defined

.include "../../mk/compiler.mk"

# gcc 4 on sparc64 catches an illegal instruction when compiling graphml.cpp
.if ${MACHINE_ARCH} == "sparc64" && ${CC_VERSION:Mgcc-4*}
PKG_HACKS+=		optimisation
BUILDLINK_TRANSFORM+=	opt:-O3:-O1
.endif

.endif  # BOOST_LIBS_HACKS_MK
