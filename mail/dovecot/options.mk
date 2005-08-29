# $NetBSD: options.mk,v 1.9 2005/08/29 13:15:34 tv Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dovecot
PKG_SUPPORTED_OPTIONS=	inet6 ldap mysql pam pgsql sasl ssl
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

###
### Build with OpenSSL as the underlying crypto library.
###
# (gnutls is broken in dovecot 0.99.x)
.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=        --enable-ssl=openssl
.  include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

###
### MySQL support.
###
.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--with-mysql
.  include "../../databases/mysql4-client/buildlink3.mk"
.endif

###
### PostgreSQL support.
###
.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--with-pgsql
CPPFLAGS+=		-I${BUILDLINK_DIR}/include/pgsql
.  include "../../mk/pgsql.buildlink3.mk"
.endif

###
### IPv6 support.
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

###
### LDAP directory support.
###
.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=	--with-ldap
.  include "../../databases/openldap/buildlink3.mk"
.endif

###
### IMAP-AUTH via SASL.
###
.if !empty(PKG_OPTIONS:Msasl)
CONFIGURE_ARGS+=	--with-cyrus-sasl2
.  include "../../security/cyrus-sasl2/buildlink3.mk"
.endif

###
### PAM support.
###
.if !empty(PKG_OPTIONS:Mpam)
CONFIGURE_ARGS+=	--with-pam
.  include "../../mk/pam.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-pam
.endif
