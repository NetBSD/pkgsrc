# $NetBSD: options.mk,v 1.1 2004/08/01 07:04:45 jlam Exp $

# Global and legacy options
.if defined(DOVECOT_USE_GNUTLS) || defined(DOVECOT_USE_MYSQL) || \
    defined(DOVECOT_USE_PGSQL) || defined(USE_INET6) || \
    defined(USE_OPENLDAP) || defined(USE_SASL2)
.  if !defined(PKG_OPTIONS.dovecot)
.    if defined(DOVECOT_USE_GNUTLS) && !empty(DOVECOT_USE_GNUTLS:M[Yy][Ee][Ss])
PKG_OPTIONS.dovecot+=	gnutls
.    endif
.    if defined(DOVECOT_USE_MYSQL) && !empty(DOVECOT_USE_MYSQL:M[Yy][Ee][Ss])
PKG_OPTIONS.dovecot+=	mysql
.    endif
.    if defined(DOVECOT_USE_PGSQL) && !empty(DOVECOT_USE_PGSQL:M[Yy][Ee][Ss])
PKG_OPTIONS.dovecot+=	pgsql
.    endif
.    if defined(USE_INET6) && !empty(USE_INET6:M[Yy][Ee][Ss])
PKG_OPTIONS.dovecot+=	inet6
.    endif
.    if defined(USE_OPENLDAP) && !empty(USE_OPENLDAP:M[Yy][Ee][Ss])
PKG_OPTIONS.dovecot+=	openldap
.    endif
.    if defined(USE_SASL2) && !empty(USE_SASL2:M[Yy][Ee][Ss])
PKG_OPTIONS.dovecot+=	sasl
.    endif
.  endif
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.dovecot
PKG_SUPPORTED_OPTIONS=	gnutls inet6 ldap mysql pgsql sasl
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls)
CONFIGURE_ARGS+=	--enable-ssl=gnutls
.  include "../../security/gnutls/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --enable-ssl=openssl
.  include "../../security/openssl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--with-mysql
.  include "../../databases/mysql4-client/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--with-pgsql
CPPFLAGS+=		-I${BUILDLINK_DIR}/include/pgsql
.  include "../../mk/pgsql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=	--with-ldap
.  include "../../databases/openldap/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msasl)
CONFIGURE_ARGS+=	--with-cyrus-sasl2
.  include "../../security/cyrus-sasl2/buildlink3.mk"
.endif
