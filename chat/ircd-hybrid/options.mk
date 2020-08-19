# $NetBSD: options.mk,v 1.8 2020/08/19 17:53:15 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ircd-hybrid

PKG_OPTIONS_OPTIONAL_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=		gnutls openssl wolfssl

PKG_OPTIONS_LEGACY_OPTS+=	ssl:openssl

PKG_SUGGESTED_OPTIONS=	openssl

.include "../../mk/bsd.options.mk"

###
### SSL support
###
.if !empty(PKG_OPTIONS:Mopenssl)
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
