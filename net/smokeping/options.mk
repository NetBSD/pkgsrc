# $NetBSD: options.mk,v 1.1 2006/08/09 21:48:53 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.smokeping

PKG_SUPPORTED_OPTIONS=	smokeping-speedycgi inet6

###
### Just here to ease migration to the options framework
###
.if defined(USE_SPEEDY) && ${USE_SPEEDY} == "YES"
PKG_SUGGESTED_OPTIONS+=	smokeping-speedycgi
.endif

.include "../../mk/bsd.options.mk"

###
### Use SpeedyCGI to get the smokeping WWW interface running a lot faster
###
.if !empty(PKG_OPTIONS:Msmokeping-speedycgi)
DEPENDS+=	SpeedyCGI-[0-9]*:../../www/SpeedyCGI
INTERP=		speedy
.else
INTERP=		perl
.endif

###
### ipv6 support
###
.if !empty(PKG_OPTIONS:Minet6)
DEPENDS+=	p5-Socket6-[0-9]*:../../net/p5-Socket6
.endif
