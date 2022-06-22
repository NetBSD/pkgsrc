# $NetBSD: platform.mk,v 1.3 2022/06/22 10:12:30 nia Exp $

.if !defined(PLATFORM_SUPPORTS_JACK)
.  include "../../mk/bsd.fast.prefs.mk"

JACK_PLATFORMS+=	Darwin-*-*
JACK_PLATFORMS+=	Linux-*-*

.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} >= 090000
PLATFORM_SUPPORTS_JACK=	yes
.endif

.  for _jack_platform in ${JACK_PLATFORMS}
.    if !empty(MACHINE_PLATFORM:M${_jack_platform})
PLATFORM_SUPPORTS_JACK=	yes
.    endif
.  endfor

PLATFORM_SUPPORTS_JACK?=	no

.endif # !defined(PLATFORM_SUPPORTS_JACK)
