# $NetBSD: options.mk,v 1.4 2004/08/22 19:32:51 jlam Exp $

.if defined(DOVECOT_USE_GNUTLS) && !empty(DOVECOT_USE_GNUTLS:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	gnutls
.endif
.if defined(DOVECOT_USE_MYSQL) && !empty(DOVECOT_USE_MYSQL:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	mysql
.endif
.if defined(DOVECOT_USE_PGSQL) && !empty(DOVECOT_USE_PGSQL:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	pgsql
.endif
.if defined(USE_INET6) && !empty(USE_INET6:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	inet6
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.dovecot
PKG_SUPPORTED_OPTIONS=	gnutls inet6 ldap mysql pgsql sasl
.include "../../mk/bsd.options.mk"

###
### Build with GNU TLS or OpenSSL as the underlying crypto library.
###
.if !empty(PKG_OPTIONS:Mgnutls)
CONFIGURE_ARGS+=	--enable-ssl=gnutls
.  include "../../security/gnutls/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --enable-ssl=openssl
.  include "../../security/openssl/buildlink3.mk"
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
