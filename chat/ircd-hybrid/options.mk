# $NetBSD: options.mk,v 1.7 2020/02/04 20:40:18 fox Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ircd-hybrid

PKG_OPTIONS_OPTIONAL_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=		gnutls ssl wolfssl

PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

###
### SSL support
###
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-tls=openssl
.elif !empty(PKG_OPTIONS:Mgnutls)
.  include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=	--with-tls=gnutls
.elif !empty(PKG_OPTIONS:Mwolfssl)
.  include "../../security/wolfssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-tls=wolfssl
.else
CONFIGURE_ARGS+=	--with-tls=none
.endif
