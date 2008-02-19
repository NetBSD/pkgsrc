# $NetBSD: options.mk,v 1.1 2008/02/19 18:45:41 jlam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.couriertcpd
PKG_SUPPORTED_OPTIONS=		inet6
PKG_OPTIONS_REQUIRED_GROUPS=	tls
PKG_OPTIONS_GROUP.tls=		gnutls ssl
PKG_SUGGESTED_OPTIONS=		inet6 ssl

.include "../../mk/bsd.options.mk"

###
### Build with OpenSSL or GNU TLS as the underlying crypto library.
###
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mgnutls)
.  include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gnutls
.endif

###
### IPv6 support.
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--with-ipv6
.else
CONFIGURE_ARGS+=	--without-ipv6
.endif
