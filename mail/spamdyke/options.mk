# $NetBSD: options.mk,v 1.2 2008/02/25 07:38:00 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.spamdyke
PKG_SUPPORTED_OPTIONS=	tls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtls)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-tls
.else
CONFIGURE_ARGS+=	--disable-tls
.endif
