# $NetBSD: options.mk,v 1.2 2004/10/29 07:07:44 xtraeme Exp $

# Legacy options
.if !empty(PURE_FTPD_USE_MYSQL:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	mysql
.endif
.if !empty(PURE_FTPD_USE_PGSQL:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	pgsql
.endif
.if !empty(PURE_FTPD_USE_TLS:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	ssl
.endif
.if !empty(PURE_FTPD_USE_VIRTUAL_CHROOT:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	virtualchroot
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.pureftpd
PKG_SUPPORTED_OPTIONS=	ldap mysql pgsql ssl virtualchroot
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap
.endif

.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql
CPPFLAGS+=		-I${BUILDLINK_PREFIX.mysql-client}/include/mysql
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pgsql
BUILD_DEFS+=		PURE_FTPD_USE_PGSQL
.endif

.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-tls
BUILD_DEFS+=		PURE_FTPD_USE_TLS
.endif

.if !empty(PKG_OPTIONS:Mvirtualchroot)
CONFIGURE_ARGS+=	--with-virtualchroot
BUILD_DEFS+=		PURE_FTPD_USE_VIRTUAL_CHROOT
.endif
