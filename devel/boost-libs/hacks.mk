# $NetBSD: hacks.mk,v 1.3 2012/08/15 18:28:21 jdc Exp $

.if !defined(BOOST_LIBS_HACKS_MK)
BOOST_LIBS_HACKS_MK=   defined

.include "../../mk/compiler.mk"

# gcc 4 on sparc64 catches an illegal instruction when compiling graphml.cpp
.if ${MACHINE_ARCH} == "sparc64" && !empty(CC_VERSION:Mgcc-4*)
PKG_HACKS+=		optimisation
BUILDLINK_TRANSFORM+=   rename:-O3:-O1
.endif

.endif  # BOOST_LIBS_HACKS_MK
