# $NetBSD: options.mk,v 1.2 2009/02/09 13:34:51 joerg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libfetch
PKG_SUPPORTED_OPTIONS=
PKG_SUGGESTED_OPTIONS=

.include "../../net/libfetch/buildlink3.mk"

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopenssl)
MAKE_ENV+=		FETCH_WITH_OPENSSL=yes

.include "../../security/openssl/buildlink3.mk"
.else
MAKE_ENV+=		FETCH_WITH_OPENSSL=no
.endif
