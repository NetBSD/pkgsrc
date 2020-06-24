# $NetBSD: hacks.mk,v 1.4 2020/06/24 16:10:31 hauke Exp $

.if !defined(XEMACS_CURRENT_HACKS_MK)
XEMACS_CURRENT_HACKS_MK=	defined

.include "../../mk/compiler.mk"

### Position-independent code does not rhyme well with dumped emacsen.
###
.if !empty(CC_VERSION:Mgcc-[6789].*)
PKG_HACKS+=		disable-gcc-pie
CFLAGS+=		-no-pie
.endif

.if !empty(CC_VERSION:Mclang-*)
PKG_HACKS+=		disable-clang-pie
CFLAGS+=		-fno-pie
.endif

.endif  # XEMACS_CURRENT_HACKS_MK
