# $NetBSD: options.mk,v 1.1.2.2 2012/02/23 15:53:56 tron Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.putty
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CFLAGS+=	-DIPV6
.endif
