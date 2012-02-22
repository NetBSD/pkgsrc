# $NetBSD: options.mk,v 1.1 2012/02/22 15:27:13 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.putty
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CFLAGS+=	-DIPV6
.endif
