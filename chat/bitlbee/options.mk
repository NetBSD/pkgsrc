# $NetBSD: options.mk,v 1.1 2019/07/28 15:37:26 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.bitlbee
PKG_SUPPORTED_OPTIONS=		inet6 otr
PKG_SUGGESTED_OPTIONS=		inet6 otr

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--ipv6=1
.else
CONFIGURE_ARGS+=	--ipv6=0
.endif

.if !empty(PKG_OPTIONS:Motr)
CONFIGURE_ARGS+=	--otr=1
.include "../../chat/libotr/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--otr=0
.endif
