# $NetBSD: options.mk,v 1.1 2005/06/13 16:57:02 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.poppassd
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ENV+=		O_DEFS="${O_DEFS}" CFLAGS="-DINET6"
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
