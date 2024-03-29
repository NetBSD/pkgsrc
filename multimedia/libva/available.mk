# $NetBSD: available.mk,v 1.12 2023/08/05 08:09:54 nia Exp $


.include "../../mk/bsd.prefs.mk"

# At the moment VAAPI is available only for XXX.  The following
# condition is here to NOT list these platforms in multiple places,
# i.e. in mplayer, xine, xbmc etc.  Have a look at buildlink3.mk too.

VAAPI_AVAILABLE=	no

# The following should be kept up-to-date!
.if ${OPSYS} == "DragonFly"
VAAPI_AVAILABLE=	yes
.elif ${OPSYS} == "FreeBSD"
VAAPI_AVAILABLE=	yes
.elif ${OPSYS} == "NetBSD"
# Requires xcb/dri3.h, not shipped with NetBSD 8
.  if ${OPSYS_VERSION} > 090000 || ${X11_TYPE} == "modular"
VAAPI_AVAILABLE=	yes
.  endif
.elif ${OPSYS} == "Linux"
VAAPI_AVAILABLE=	yes
.endif
