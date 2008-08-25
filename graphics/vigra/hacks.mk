# $NetBSD: hacks.mk,v 1.1.1.1 2008/08/25 18:17:56 bjs Exp $
#
.if !defined(VIGRA_HACKS_MK)
VIGRA_HACKS_MK=	# empty
.  include "../../mk/compiler.mk"
#
.  if !empty(CC_VERSION:Mgcc-[34]*)
PKG_HACKS+=	no-strict-aliasing
CFLAGS+=	-fno-strict-aliasing
.  endif
.endif
