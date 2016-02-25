# $NetBSD: available.mk,v 1.3 2016/02/25 15:49:44 jperkin Exp $

# At the moment VAAPI is available only for XXX.  The following
# condition is here to NOT list these platforms in multiple places,
# i.e. in mplayer, xine, xbmc etc.  Have a look at buildlink3.mk too.

# The following should be kept up-to-date!
OPSYSVARS+=			VAAPI_AVAILABLE
VAAPI_AVAILABLE.Linux=		yes
VAAPI_AVAILABLE.FreeBSD=	yes
VAAPI_AVAILABLE.OpenBSD=	yes
VAAPI_AVAILABLE.*=		no
