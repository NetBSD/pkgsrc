# $NetBSD: options.mk,v 1.3 2009/02/18 08:36:53 joerg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libfetch
PKG_SUPPORTED_OPTIONS=
PKG_SUGGESTED_OPTIONS=

.include "../../net/libfetch/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.libfetch:Mopenssl)
PKG_SUPPORTED_OPTIONS+=	openssl
PKG_SUGGESTED_OPTIONS+=	openssl
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopenssl)
MAKE_ENV+=		FETCH_WITH_OPENSSL=yes

.include "../../security/openssl/buildlink3.mk"
.else
MAKE_ENV+=		FETCH_WITH_OPENSSL=no
.endif
