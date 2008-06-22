# $NetBSD: options.mk,v 1.21 2008/06/22 17:41:23 ghen Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dovecot
PKG_SUPPORTED_OPTIONS=	gssapi inet6 kqueue ldap mysql pam pgsql sasl sqlite
PKG_OPTIONS_OPTIONAL_GROUPS= ssl
PKG_OPTIONS_GROUP.ssl=	gnutls ssl
PKG_SUGGESTED_OPTIONS=	ssl

.if defined(PKG_HAVE_KQUEUE)
PKG_SUGGESTED_OPTIONS+=	kqueue
.endif

.include "../../mk/bsd.options.mk"

###
### Build with OpenSSL or GNU TLS as the underlying crypto library.
###
.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--with-ssl=openssl
CONFIGURE_ENV+=		SSL_CFLAGS="-I${BUILDLINK_PREFIX.openssl}/include"
CONFIGURE_ENV+=		SSL_LIBS="-lssl -lcrypto"
.  include "../../security/openssl/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mgnutls)
CONFIGURE_ARGS+=	--with-ssl=gnutls
.  include "../../security/gnutls/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

###
### MySQL support.
###
.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--with-mysql
.  include "../../mk/mysql.buildlink3.mk"
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
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

###
### LDAP directory support.
###
.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=	--with-ldap
.  include "../../databases/openldap-client/buildlink3.mk"
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

###
### SQLite support.
###
.if !empty(PKG_OPTIONS:Msqlite)
CONFIGURE_ARGS+=	--with-sqlite
.  include "../../databases/sqlite3/buildlink3.mk"
.endif

###
### kqueue support.
###
.if !empty(PKG_OPTIONS:Mkqueue)
CONFIGURE_ARGS+=	--with-ioloop=kqueue
CONFIGURE_ARGS+=	--with-notify=kqueue
.else
# use the defaults
.endif

###
### GSSAPI support.
###
.if !empty(PKG_OPTIONS:Mgssapi)
CONFIGURE_ARGS+=	--with-gssapi
.  include "../../mk/krb5.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gssapi
.endif
