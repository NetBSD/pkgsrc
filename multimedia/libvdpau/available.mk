# $NetBSD: available.mk,v 1.6 2017/03/16 19:21:09 maya Exp $

.include "../../mk/bsd.prefs.mk"

PKG_SUPPORTED_OPTIONS+=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

VDPAU_AVAILABLE=	no

.if !empty(PKG_OPTIONS:Mx11)
.if ${OPSYS} != "Darwin" && (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64")
VDPAU_AVAILABLE=	yes
.endif
.endif
