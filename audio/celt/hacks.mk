# $NetBSD: hacks.mk,v 1.2 2019/11/02 21:09:13 rillig Exp $
#

.if !defined(CELT_HACKS_MK)
CELT_HACKS_MK=	# empty
.include "../../mk/compiler.mk"
###
### XXX Remove this if unneeded in the future.
###
.if !empty(CC_VERSION:Mgcc-[34]*)
CFLAGS+=	-fno-strict-aliasing
PKG_HACKS+=	no-strict-aliasing
.endif
.endif
