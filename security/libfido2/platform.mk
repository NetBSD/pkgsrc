# $NetBSD: platform.mk,v 1.1 2023/12/01 11:00:28 nia Exp $

.if !defined(PLATFORM_SUPPORTS_FIDO2)
.include "../../mk/bsd.fast.prefs.mk"

FIDO2_PLATFORMS+=	Darwin-*-aarch64
FIDO2_PLATFORMS+=	Darwin-*-x86_64
FIDO2_PLATFORMS+=	FreeBSD-*-*
FIDO2_PLATFORMS+=	MidnightBSD-*-*
FIDO2_PLATFORMS+=	Linux-*-*
FIDO2_PLATFORMS+=	NetBSD-*-*
FIDO2_PLATFORMS+=	OpenBSD-*-*

.for _fido2_platform in ${FIDO2_PLATFORMS}
.  if !empty(MACHINE_PLATFORM:M${_fido2_platform})
PLATFORM_SUPPORTS_FIDO2=	yes
.  endif
.endfor
PLATFORM_SUPPORTS_FIDO2?=	no

.endif # !defined(PLATFORM_SUPPORTS_FIDO2)
