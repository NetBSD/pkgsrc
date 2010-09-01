# $NetBSD: available.mk,v 1.1.1.1 2010/09/01 20:41:45 wiz Exp $

.include "../../mk/bsd.prefs.mk"

# At the moment VDPAU is available only for Linux, FreeBSD and
# [Open]Solaris.  The following condition is here to NOT list these
# platforms in multiple places, i.e. in mplayer, xine, xbmc etc.
# Have a look at buildlink3.mk too.
VDPAU_AVAILABLE_ON=	Linux FreeBSD SunOS
.if !empty(VDPAU_AVAILABLE_ON:M${OPSYS})
VDPAU_AVAILABLE=	yes
.else
VDPAU_AVAILABLE=	no
.endif
