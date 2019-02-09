# $NetBSD: options.mk,v 1.2 2019/02/09 20:13:02 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.atheme

PKG_SUPPORTED_OPTIONS=	ldap ssl atheme-large-net
PKG_SUGGESTED_OPTIONS=	ssl

PLIST_VARS+=		ldap

.include "../../mk/bsd.options.mk"

###
### Compile in OpenSSL support
###
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ssl
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
PLIST.ldap=		yes
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

###
### Large network support (i.e. > 2000 users)
###
.if !empty(PKG_OPTIONS:Matheme-large-net)
CONFIGURE_ARGS+=	--enable-large-net
.endif
