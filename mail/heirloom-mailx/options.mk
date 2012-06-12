# $NetBSD: options.mk,v 1.2 2012/06/12 15:45:58 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.heirloom-mailx
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.prefs.mk"

.if !empty(IPV6_READY:M[Yy][Ee][Ss])
PKG_SUGGESTED_OPTIONS+=	inet6
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
MAKE_ENV+=		IPv6=-DHAVE_IPv6_FUNCS
.endif
