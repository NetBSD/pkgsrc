# $NetBSD: options.mk,v 1.9 2010/02/04 12:03:51 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pureftpd
PKG_SUPPORTED_OPTIONS=	ldap mysql pgsql ssl virtualchroot utf8

PKG_OPTIONS_LEGACY_VARS+=	PURE_FTPD_USE_MYSQL:mysql
PKG_OPTIONS_LEGACY_VARS+=	PURE_FTPD_USE_PGSQL:pgsql
PKG_OPTIONS_LEGACY_VARS+=	PURE_FTPD_USE_TLS:ssl
PKG_OPTIONS_LEGACY_VARS+=	PURE_FTPD_USE_VIRTUAL_CHROOT:virtualchroot

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap
.endif

.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pgsql
.endif

.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-tls
CONFIGURE_ARGS+=	--with-certfile=${SSLKEYS}/pure-ftpd.pem
SUBST_CLASSES+=		cert
SUBST_STAGE.cert=	pre-configure
SUBST_FILES.cert=	README README.TLS
SUBST_SED.cert=		-e "s|/etc/ssl/private|${SSLKEYS}|g"
.endif

.if !empty(PKG_OPTIONS:Mvirtualchroot)
CONFIGURE_ARGS+=	--with-virtualchroot
.endif

.if !empty(PKG_OPTIONS:Mutf8)
# Experimental
.  include "../../converters/libiconv/buildlink3.mk"
CONFIGURE_ARGS+=	--with-rfc2640
.endif
