# $NetBSD: options.mk,v 1.2 2010/11/09 15:23:11 ghen Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dovecot
PKG_SUPPORTED_OPTIONS=	dovecot-sieve gssapi
PKG_SUPPORTED_OPTIONS+=	kqueue ldap mysql pam pgsql sqlite
PKG_OPTIONS_OPTIONAL_GROUPS= ssl
PKG_OPTIONS_GROUP.ssl=	gnutls ssl
PKG_SUGGESTED_OPTIONS=	ssl

.if defined(PKG_HAVE_KQUEUE)
PKG_SUGGESTED_OPTIONS+=	kqueue
.endif

.include "../../mk/bsd.options.mk"

###
### Build with OpenSSL or GNU TLS as the underlying crypto library
###
.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--with-ssl=openssl
CONFIGURE_ENV+=		SSL_CFLAGS="-I${BUILDLINK_PREFIX.openssl}/include"
CONFIGURE_ENV+=		SSL_LIBS="-lssl -lcrypto"
BUILDLINK_API_DEPENDS.openssl+=openssl>=0.9.8a
.  include "../../security/openssl/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mgnutls)
CONFIGURE_ARGS+=	--with-ssl=gnutls
.  include "../../security/gnutls/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

###
### MySQL support
###
.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--with-mysql
.  include "../../mk/mysql.buildlink3.mk"
.endif

###
### PostgreSQL support
###
.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--with-pgsql
CPPFLAGS+=		-I${BUILDLINK_DIR}/include/pgsql
.  include "../../mk/pgsql.buildlink3.mk"
.endif

###
### LDAP directory support
###
.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=	--with-ldap
.  include "../../databases/openldap-client/buildlink3.mk"
.endif

###
### PAM support
###
.if !empty(PKG_OPTIONS:Mpam)
CONFIGURE_ARGS+=	--with-pam
.  include "../../mk/pam.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-pam
.endif

###
### SQLite support
###
.if !empty(PKG_OPTIONS:Msqlite)
CONFIGURE_ARGS+=	--with-sqlite
.  include "../../databases/sqlite3/buildlink3.mk"
.endif

###
### kqueue support
###
.if !empty(PKG_OPTIONS:Mkqueue)
CONFIGURE_ARGS+=	--with-ioloop=kqueue
CONFIGURE_ARGS+=	--with-notify=kqueue
.else
# use the defaults
.endif

###
### GSSAPI support
###
.if !empty(PKG_OPTIONS:Mgssapi)
CONFIGURE_ARGS+=	--with-gssapi
.  include "../../mk/krb5.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gssapi
.endif

###
### Pigeonhole Sieve plugin
###
.if !empty(PKG_OPTIONS:Mdovecot-sieve) || make(distinfo) || make(makesum)
# We can't simply use CONFIGURE_DIRS+= and BUILD_DIRS+=
#  because dovecot must be built before sieve can be configured/built.
# So use post-build in Makefile. Sigh.
#
# Default so we can use += below
DISTFILES=		${DEFAULT_DISTFILES}
PLIST_SRC=		${PLIST_SRC_DFLT:Q}
INSTALL_DIRS=		${WRKSRC}

DISTFILES+=		dovecot-${DOVECOT_VERSION}-pigeonhole-${SIEVE_VERSION}.tar.gz
SITES.dovecot-${DOVECOT_VERSION}-pigeonhole-${SIEVE_VERSION}.tar.gz=\
			${DOVECOT_SIEVE_SITES}
WRKSRC.sieve=		${WRKDIR}/dovecot-${DOVECOT_VERSION}-pigeonhole-${SIEVE_VERSION}
CONFIGURE_ARGS.sieve=	--with-dovecot=${WRKSRC}
CONFIGURE_ARGS.sieve+=	--docdir=${PREFIX}/share/doc
INSTALL_DIRS+=		${WRKSRC.sieve}
SUBST_FILES.egdir+=	${WRKSRC.sieve}/doc/example-config/conf.d/Makefile.in
PLIST_SRC+=		${PKGDIR}/PLIST.sieve
CONF_FILES+=		${EGDIR}/conf.d/20-managesieve.conf ${PKG_SYSCONFDIR}/dovecot/conf.d/20-managesieve.conf
CONF_FILES+=		${EGDIR}/conf.d/90-sieve.conf ${PKG_SYSCONFDIR}/dovecot/conf.d/90-sieve.conf
.endif # dovecot-sieve
