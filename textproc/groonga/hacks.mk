# $NetBSD: hacks.mk,v 1.3 2014/05/31 08:30:27 obache Exp $

.if !defined(GROONGA_HACKS_MK)
GROONGA_HACKS_MK=	# defined

.include "../../mk/compiler.mk"

# Build with optimization. Avoids crash in expr.c
.if !empty(CC_VERSION:Mclang-*) && !empty(CFLAGS:M-O*)
PKG_HACKS+=	clang-optimization
UNLIMIT_RESOURCES+=	datasize
.endif

.endif
