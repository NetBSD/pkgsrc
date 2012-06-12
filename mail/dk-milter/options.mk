# $NetBSD: options.mk,v 1.2 2012/06/12 15:45:57 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dk-milter
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

###
### IPv6 support.
###
.if !empty(PKG_OPTIONS:Minet6)
SUBST_SED.libs+=	-e 's|@INET6@||'
.else
SUBST_SED.libs+=	-e 's|@INET6@|dnl|'
.endif
