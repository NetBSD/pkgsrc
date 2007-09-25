# $NetBSD: hacks.mk,v 1.1 2007/09/25 04:18:26 bjs Exp $

.if !defined(NSPR_HACKS_MK)
NSPR_HACKS_MK=	# defined

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-[34]*)
CFLAGS+=	-fno-strict-aliasing
PKG_HACKS+=	no-strict-aliasing
.endif

.endif
