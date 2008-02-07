# $NetBSD: options.mk,v 1.1.1.1 2008/02/07 01:48:22 joerg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libfetch
PKG_SUPPORTED_OPTIONS=	inet6 openssl
PKG_SUGGESTED_OPTIONS=	inet6 openssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
MAKE_ENV+=		FETCH_WITH_INET6=yes
.else
MAKE_ENV+=		FETCH_WITH_INET6=no
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
MAKE_ENV+=		FETCH_WITH_OPENSSL=yes
.else
MAKE_ENV+=		FETCH_WITH_OPENSSL=no
.endif
