# $NetBSD: options.mk,v 1.3 2015/03/15 15:28:57 mef Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dk-milter
PKG_SUPPORTED_OPTIONS=	arlib inet6
PKG_SUGGESTED_OPTIONS=	arlib inet6

.include "../../mk/bsd.options.mk"

###
### IPv6 support.
###
.if !empty(PKG_OPTIONS:Minet6)
SUBST_SED.libs+=	-e 's|@INET6@||g'
.else
SUBST_SED.libs+=	-e 's|@INET6@|dnl|g'
.endif

###
### Use asynchronous DNS resolver library shipping with dk-milter.
###
.if !empty(PKG_OPTIONS:Marlib)
SUBST_SED.libs+=	-e 's|@RESOLVLIB@||g'
SUBST_SED.libs+=	-e 's|@ARLIB@||g'
.else
SUBST_SED.libs+=	-e 's|@RESOLVLIB@|resolv bind|g'
SUBST_SED.libs+=	-e 's|@ARLIB@|dnl|g'
.endif
