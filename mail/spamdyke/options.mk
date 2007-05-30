# $NetBSD: options.mk,v 1.1 2007/05/30 05:58:10 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.spamdyke
PKG_SUPPORTED_OPTIONS=	tls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtls)
.  include "../../security/openssl/buildlink3.mk"
MAKE_ENV+=	CFLAGS_TLS="-DTLS"
MAKE_ENV+=	LFLAGS_TLS="-lssl -lcrypto"
.else
MAKE_ENV+=	CFLAGS_TLS=""
MAKE_ENV+=	LFLAGS_TLS=""
.endif
