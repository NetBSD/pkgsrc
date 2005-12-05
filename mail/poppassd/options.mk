# $NetBSD: options.mk,v 1.2 2005/12/05 14:12:29 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.poppassd
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ENV+=		O_DEFS=${O_DEFS:Q} CFLAGS="-DINET6"
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
