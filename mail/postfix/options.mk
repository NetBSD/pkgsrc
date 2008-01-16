# $NetBSD: options.mk,v 1.27 2008/01/16 14:21:43 ghen Exp $

# Global and legacy options

PKG_OPTIONS_VAR=	PKG_OPTIONS.postfix
PKG_SUPPORTED_OPTIONS=	bdb ldap mysql mysql4 pcre pgsql sasl tls postfix-stress
PKG_SUGGESTED_OPTIONS=	tls

.include "../../mk/bsd.options.mk"

###
### Support "hash" (Berkeley DB) map type.
###
.if empty(PKG_OPTIONS:Mbdb)
PKG_OPTIONS+=	bdb		# "hash" map type is mandatory
.endif
.if !empty(PKG_OPTIONS:Mbdb)
.  include "../../mk/bdb.buildlink3.mk"
CCARGS+=	-DHAS_DB
AUXLIBS+=	${BDB_LIBS}
.endif

###
### STARTTLS support
###
.if !empty(PKG_OPTIONS:Mtls)
.  include "../../security/openssl/buildlink3.mk"
CCARGS+=	-DUSE_TLS
AUXLIBS+=	-L${BUILDLINK_PREFIX.openssl}/lib			\
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib	\
		-lssl -lcrypto
.endif

###
### Support "pcre" map type for regular expressions.
###
.if !empty(PKG_OPTIONS:Mpcre)
.  include "../../devel/pcre/buildlink3.mk"
CCARGS+=	-DHAS_PCRE
AUXLIBS+=	-L${BUILDLINK_PREFIX.pcre}/lib				\
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.pcre}/lib	\
		-lpcre
.else
CCARGS+=	-DNO_PCRE
.endif

###
### Support LDAP directories for table lookups.
###
.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
CCARGS+=	-DHAS_LDAP
AUXLIBS+=	-L${BUILDLINK_PREFIX.openldap-client}/lib			\
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openldap-client}/lib	\
		-lldap -llber
.endif

###
### Support using a MySQL database server for table lookups.
###
.if !empty(PKG_OPTIONS:Mmysql4)
.  include "../../mk/mysql.buildlink3.mk"
CCARGS+=	-DHAS_MYSQL
CCARGS+=	`${BUILDLINK_PREFIX.mysql-client}/bin/mysql_config --include`
AUXLIBS+=	`${BUILDLINK_PREFIX.mysql-client}/bin/mysql_config --libs`
.elif !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
CCARGS+=	-DHAS_MYSQL -I${BUILDLINK_PREFIX.mysql-client}/include/mysql
AUXLIBS+=	-L${BUILDLINK_PREFIX.mysql-client}/lib/mysql		\
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.mysql-client}/lib/mysql \
		-lmysqlclient -lz -lm
.endif

###
### Support using a PostgreSQL database server for table lookups.
###
.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
.  include "../../security/openssl/buildlink3.mk"
CCARGS+=	-DHAS_PGSQL -I${PGSQL_PREFIX}/include/pgsql
AUXLIBS+=	-L${PGSQL_PREFIX}/lib -lpq \
		-L${BUILDLINK_PREFIX.openssl}/lib -lcrypt -lssl -lcrypto
.endif

###
### Cyrus SASL support for SMTP authentication.
### (Dovcot SASL support is built in by default.)
###
.if !empty(PKG_OPTIONS:Msasl)
.  include "../../security/cyrus-sasl/buildlink3.mk"
BUILDLINK_INCDIRS.cyrus-sasl=	include/sasl
SASLLIBDIR=	${PREFIX}/lib/sasl2
PWCHECK_METHOD=	auxprop
CCARGS+=	-DUSE_CYRUS_SASL
AUXLIBS+=	-L${BUILDLINK_PREFIX.cyrus-sasl}/lib			\
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.cyrus-sasl}/lib \
		-lsasl2
PLIST_SUBST+=	SASL=
MESSAGE_SRC+=	${PKGDIR}/MESSAGE.sasl
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
MESSAGE_SUBST+=	SASLLIBDIR=${SASLLIBDIR}
.else
PLIST_SUBST+=	SASL="@comment "
CCARGS+=	-DDEF_SERVER_SASL_TYPE=\"dovecot\"
.endif

###
### Postfix stress-adaptive behaviour, back-ported from Postfix 2.5
### See http://www.postfix.org/STRESS_README.html#adapt
###
.if !empty(PKG_OPTIONS:Mpostfix-stress)
PATCHFILES=	postfix-2.4-stress-patch.gz
PATCH_SITES=	${MASTER_SITES}
.endif
