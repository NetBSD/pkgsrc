# $NetBSD: hacks.mk,v 1.2 2014/04/03 07:16:49 obache Exp $

.if !defined(GROONGA_HACKS_MK)
GROONGA_HACKS_MK=	# defined

.include "../../mk/compiler.mk"

# Build with optimization. Avoids crash in expr.c
.if !empty(CC_VERSION:Mclang-*) && !empty(CFLAGS:M-O*)
PKG_HACKS+=	clang-optimization
UNLIMIT_RESOURCES=	datasize
.endif

.endif
