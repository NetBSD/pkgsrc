# $NetBSD: available.mk,v 1.1 2013/04/14 00:30:02 cheusov Exp $

.include "../../mk/bsd.prefs.mk"

# At the moment VAAPI is available only for XXX.  The following
# condition is here to NOT list these platforms in multiple places,
# i.e. in mplayer, xine, xbmc etc.  Have a look at buildlink3.mk too.

# Enable VAAPI everywhere for now
VAAPI_AVAILABLE=	yes
