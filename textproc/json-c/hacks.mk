# $NetBSD: hacks.mk,v 1.1.2.2 2014/07/17 22:32:01 tron Exp $

.if !defined(JSON_C_HACKS_MK)
JSON_C_HACKS_MK=	# defined

# json-c>=0.12 depends on builtin functions which enabled with i486 and
# later with GCC.
#
.include "../../mk/compiler.mk"
.if !empty(MACHINE_PLATFORM:MNetBSD-[0-5].*-i386) && !empty(CC_VERSION:Mgcc-*)
GNU_ARCH.i386=		i486
CFLAGS+=		-march=i486
.endif

.endif
