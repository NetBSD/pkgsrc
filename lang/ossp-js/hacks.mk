# $NetBSD: hacks.mk,v 1.1.1.1 2008/02/06 04:22:33 bjs Exp $

.if !defined(OSSP_JS_HACKS_MK)
OSSP_JS_HACKS_MK=	# defined

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-[34]*)
CFLAGS+=	-fno-strict-aliasing
PKG_HACKS+=	no-strict-aliasing
.endif

.endif
