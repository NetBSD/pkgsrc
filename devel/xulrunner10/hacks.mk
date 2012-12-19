# $NetBSD: hacks.mk,v 1.2 2012/12/19 12:50:00 joerg Exp $

.if !defined(XULRUNNER10_HACKS_MK)
XULRUNNER10_HACKS_MK=	defined

.include "../../mk/bsd.fast.prefs.mk"
.include "../../mk/compiler.mk"

# PR pkg/44912: gcc generates unaligned SSE2 references
.if !empty(PKGSRC_COMPILER:Mgcc) && !empty(CC_VERSION:Mgcc-4.[0-3]*) && !empty(MACHINE_PLATFORM:M*-*-i386)
PKG_HACKS+=		optimization
BUILDLINK_TRANSFORM+=	rm:-march=[-_A-Za-z0-9]*
.endif

.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=		-Wno-return-type-c-linkage
.endif

.endif	# XULRUNNER10_HACKS_MK
