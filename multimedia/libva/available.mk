# $NetBSD: available.mk,v 1.9 2017/03/16 19:29:39 maya Exp $

.include "../../mk/bsd.prefs.mk"

PKG_SUPPORTED_OPTIONS+=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

# At the moment VAAPI is available only for XXX.  The following
# condition is here to NOT list these platforms in multiple places,
# i.e. in mplayer, xine, xbmc etc.  Have a look at buildlink3.mk too.

VAAPI_AVAILABLE=	no

.if !empty(PKG_OPTIONS:Mx11)
# The following should be kept up-to-date!
.if ${OPSYS} == "DragonFly"
VAAPI_AVAILABLE=	yes
.elif ${OPSYS} == "FreeBSD"
VAAPI_AVAILABLE=	yes
.elif ${OPSYS} == "NetBSD"
VAAPI_AVAILABLE=	yes
.elif ${OPSYS} == "Linux"
VAAPI_AVAILABLE=	yes
.endif
.endif
