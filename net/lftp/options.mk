# $NetBSD: options.mk,v 1.3 2005/06/01 14:06:50 wiz Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.lftp
PKG_SUPPORTED_OPTIONS=	gnutls ssl
PKG_SUGGESTED_OPTIONS=	gnutls
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls) && !empty(PKG_OPTIONS:Mssl)
PKG_FAIL_REASON+=	"Options \"gnutls\" and \"ssl\" are mutually exclusive."
.endif

.if !empty(PKG_OPTIONS:Mgnutls)
CONFIGURE_ARGS+=	--without-openssl
.include "../../security/gnutls/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--without-gnutls
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
.include "../../security/openssl/buildlink3.mk"
.endif
