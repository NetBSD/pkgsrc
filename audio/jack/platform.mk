# $NetBSD: platform.mk,v 1.5 2023/01/07 21:20:19 triaxx Exp $

.if !defined(PLATFORM_SUPPORTS_JACK)
.  include "../../mk/bsd.fast.prefs.mk"

JACK_PLATFORMS+=	Darwin-*-*
JACK_PLATFORMS+=	Linux-*-*

.  if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} >= 090000
PLATFORM_SUPPORTS_JACK=	yes
.  endif

.  for jack_platform in ${JACK_PLATFORMS}
.    if !empty(MACHINE_PLATFORM:M${jack_platform})
PLATFORM_SUPPORTS_JACK=	yes
.    endif
.  endfor

PLATFORM_SUPPORTS_JACK?=	no

.endif # !defined(PLATFORM_SUPPORTS_JACK)
