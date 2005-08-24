# $NetBSD: hacks.mk,v 1.1 2005/08/24 04:36:14 schmonz Exp $

.include "../../mk/bsd.prefs.mk"

# Avoid gcc optimizer bug on arm platforms
.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
PKG_HACKS+=	djbware-XXX-foo
GCC_REQD+=	3.0
.endif
