# $NetBSD: available.mk,v 1.8 2017/03/17 09:10:14 maya Exp $

.include "../../mk/bsd.prefs.mk"

VDPAU_AVAILABLE=	no

.if ${OPSYS} != "Darwin" && (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64")
VDPAU_AVAILABLE=	yes
.endif
