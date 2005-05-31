# $NetBSD: options.mk,v 1.2 2005/05/31 22:04:06 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xtris
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CFLAGS+=	-DINET6
.endif
