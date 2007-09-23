# $NetBSD: hacks.mk,v 1.1.1.1 2007/09/23 14:55:52 ghen Exp $

.include "../../mk/compiler.mk"

# Avoid an ICE in gcc2 on sparc64
.if !empty(CC_VERSION:Mgcc-*)
PKG_HACKS+=		sparc64-gcc2-ice
CONFIGURE_ENV+=		F77=${FALSE:Q}
.endif
