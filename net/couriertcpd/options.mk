# $NetBSD: options.mk,v 1.2 2008/02/21 15:50:29 jlam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.couriertcpd
PKG_SUPPORTED_OPTIONS=		courier-gnutls inet6
PKG_SUGGESTED_OPTIONS=		inet6

.include "../../mk/bsd.options.mk"

###
### Support using GNU TLS as the underlying crypto library; otherwise,
### default to using OpenSSL.
###
.if !empty(PKG_OPTIONS:Mcourier-gnutls)
.  include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gnutls
.else
.  include "../../security/openssl/buildlink3.mk"
.endif

###
### IPv6 support.
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--with-ipv6
.else
CONFIGURE_ARGS+=	--without-ipv6
.endif
