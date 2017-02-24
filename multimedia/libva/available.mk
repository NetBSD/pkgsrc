# $NetBSD: available.mk,v 1.7 2017/02/24 16:44:03 maya Exp $

.include "../../mk/bsd.prefs.mk"

# At the moment VAAPI is available only for XXX.  The following
# condition is here to NOT list these platforms in multiple places,
# i.e. in mplayer, xine, xbmc etc.  Have a look at buildlink3.mk too.

# The following should be kept up-to-date!
.if ${OPSYS} == "DragonFly"
VAAPI_AVAILABLE=	yes
.if ${OPSYS} == "FreeBSD"
VAAPI_AVAILABLE=	yes
.elif ${OPSYS} == "NetBSD"
VAAPI_AVAILABLE=	yes
.elif ${OPSYS} == "Linux"
VAAPI_AVAILABLE=	yes
.else
VAAPI_AVAILABLE=	no
.endif
