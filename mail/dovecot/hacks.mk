# $NetBSD: hacks.mk,v 1.3 2008/06/22 17:41:23 ghen Exp $

.include "../../mk/compiler.mk"

# Avoid an ICE in gcc2 on sparc64
.if !empty(CC_VERSION:Mgcc-*)
PKG_HACKS+=		sparc64-gcc2-ice
CONFIGURE_ENV+=		F77=${FALSE:Q}
.endif
