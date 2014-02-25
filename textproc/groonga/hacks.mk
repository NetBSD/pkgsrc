# $NetBSD: hacks.mk,v 1.1 2014/02/25 05:14:37 obache Exp $

.if !defined(GROONGA_HACKS_MK)
GROONGA_HACKS_MK=	# defined

.include "../../mk/compiler.mk"

# Build without optimization. Avoids crash in expr.c
.if !empty(MACHINE_PLATFORM:MNetBSD-6.99.[0-9]*-x86_64) && !empty(CC_VERSION:Mclang-*)
PKG_HACKS+=	clang-optimization
BUILDLINK_TRANSFORM+=	rename:-O[0-9]*:-O0
.endif

.endif
