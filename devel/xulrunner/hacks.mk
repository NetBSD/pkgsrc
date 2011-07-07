# $NetBSD: hacks.mk,v 1.1 2011/07/07 11:04:35 tnn Exp $

.if !defined(XULRUNNER_HACKS_MK)
XULRUNNER_HACKS_MK=	defined

.include "../../mk/bsd.fast.prefs.mk"
.include "../../mk/compiler.mk"

# PR pkg/44912: gcc generates unaliged SSE2 references
.if !empty(PKGSRC_COMPILER:Mgcc) && !empty(CC_VERSION:Mgcc-4.[0-3]*) && !empty(MACHINE_PLATFORM:M*-*-i386)
PKG_HACKS+=		optimization
BUILDLINK_TRANSFORM+=	rm:-march=[-_A-Za-z0-9]*
.endif

.endif	# XULRUNNER_HACKS_MK
