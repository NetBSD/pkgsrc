# $NetBSD: hacks.mk,v 1.6 2013/06/13 09:02:50 obache Exp $

.if !defined(COIN_HACKS_MK)
COIN_HACKS_MK=	defined

###
### Compiling Coin on NetBSD with optimization causes an internal
### compiler error.  This is a workaround for PR toolchain/33097.
### Not sure if other platforms have the same issue.
###
.include "../../mk/compiler.mk"
.if ${OPSYS} == "NetBSD" && !empty(CC_VERSION:Mgcc-3.*)
PKG_HACKS+=		optimization
BUILDLINK_TRANSFORM+=	rm:-O[0-9]*
.endif

.endif	# COIN_HACKS_MK
