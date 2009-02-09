# $NetBSD: options.mk,v 1.3 2009/02/09 13:34:02 joerg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libfetch
PKG_SUPPORTED_OPTIONS=	inet6 openssl
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../security/openssl/builtin.mk"

.if !empty(USE_BUILTIN.openssl:M[yY][eE][sS])
PKG_SUGGESTED_OPTIONS+=	openssl
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
MAKE_ENV+=		FETCH_WITH_INET6=yes
.else
MAKE_ENV+=		FETCH_WITH_INET6=no
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
MAKE_ENV+=		FETCH_WITH_OPENSSL=yes

.include "../../security/openssl/buildlink3.mk"
.else
MAKE_ENV+=		FETCH_WITH_OPENSSL=no
.endif
