# $NetBSD: hacks.mk,v 1.2 2005/09/02 01:40:20 schmonz Exp $

.include "../../mk/bsd.prefs.mk"

# Avoid gcc optimizer bug on arm platforms
.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
PKG_HACKS+=	arm-gcc2-optimizer
GCC_REQD+=	3.0
.endif
