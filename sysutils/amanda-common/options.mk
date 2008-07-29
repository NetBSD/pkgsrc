# $NetBSD: options.mk,v 1.1 2008/07/29 17:21:39 pgoyette Exp $

# Since amanda's ipv6 usage is broken, turn it off by default.

PKG_OPTIONS_VAR=	PKG_OPTIONS.amanda
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--with-ipv6
.else
CONFIGURE_ARGS+=	--without-ipv6
.endif
