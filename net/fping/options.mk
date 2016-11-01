# $NetBSD: options.mk,v 1.1 2016/11/01 14:53:29 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fping
PKG_SUPPORTED_OPTIONS=	inet6

.if empty(MISSING_FEATURES:Minet6)
PKG_SUGGESTED_OPTIONS=	inet6
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	ipv6

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
PLIST.ipv6=		yes
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
