# $NetBSD: options.mk,v 1.2 2016/06/18 18:55:52 bsiegert Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.mpop
PKG_SUPPORTED_OPTIONS=		gsasl
PKG_OPTIONS_OPTIONAL_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=		gnutls ssl
PKG_SUGGESTED_OPTIONS=		ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls)
CONFIGURE_ARGS+=	--with-tls=gnutls
.  include "../../security/gnutls/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--with-tls=openssl
.  include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-tls
.endif

.if !empty(PKG_OPTIONS:Mgsasl)
CONFIGURE_ARGS+=	--enable-gsasl
.  include "../../security/gsasl/buildlink3.mk"
.endif
