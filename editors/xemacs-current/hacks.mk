# $NetBSD: hacks.mk,v 1.3 2019/04/11 16:05:24 hauke Exp $

.if !defined(XEMACS_CURRENT_HACKS_MK)
XEMACS_CURRENT_HACKS_MK=	defined

.include "../../mk/compiler.mk"

### Position-independent code does not rhyme well with
### dumped emacsen.
###
.if !empty(CC_VERSION:Mgcc-[6789].*)
PKG_HACKS+=		disable-gcc-pie
CFLAGS+=		-no-pie
.endif

.endif  # XEMACS_CURRENT_HACKS_MK
