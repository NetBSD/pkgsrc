# $NetBSD: options.mk,v 1.15 2005/02/09 06:55:10 martti Exp $

# Global and legacy options

PKG_OPTIONS_VAR=	PKG_OPTIONS.postfix
PKG_SUPPORTED_OPTIONS=	bdb inet6 ldap mysql mysql4 pcre pgsql sasl tls
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
AUXLIBS+=	${BUILDLINK_LDFLAGS.${BDB_TYPE}} ${BDB_LIBS}
.endif

###
### IPv6 and STARTTLS support (http://www.ipnet6.org/postfix/)
###
.if !empty(PKG_OPTIONS:Minet6)
.  if empty(PKG_OPTIONS:Mtls)
PKG_OPTIONS+=		tls
.  endif
IPV6TLS_PATCH=		tls+ipv6-1.26-pf-2.1.5.patch.gz
PATCHFILES+=		${IPV6TLS_PATCH}
SITES_${IPV6TLS_PATCH}=	ftp://ftp.stack.nl/pub/postfix/tls+ipv6/1.26/
PATCH_DIST_STRIP.${IPV6TLS_PATCH}=	-p1
PLIST_SRC+=		${PKGDIR}/PLIST.inet6

post-patch: darwin-inet6-fix inet6-ni_withscopeid-fix
darwin-inet6-fix:
	@cd ${WRKSRC} && ${PATCH} ${PATCH_ARGS} \
		< ${FILESDIR}/patch-darwin-inet6
inet6-ni_withscopeid-fix:
	@cd ${WRKSRC} && ${PATCH} ${PATCH_ARGS} \
		< ${FILESDIR}/patch-inet6-ni_withscopeid
.endif

###
### STARTTLS support (http://mirrors.loonybin.net/postfix_tls/)
###
.if !empty(PKG_OPTIONS:Mtls)
.  include "../../security/openssl/buildlink3.mk"
.  if empty(PKG_OPTIONS:Minet6)
TLS_PATCH=		pfixtls-0.8.18-2.1.3-0.9.7d.tar.gz
PATCHFILES+=		${TLS_PATCH}
SITES_${TLS_PATCH}=	http://mirrors.loonybin.net/postfix_tls/	\
			ftp://mirrors.loonybin.net/pub/postfix_tls/	\
			ftp://ftp.aet.tu-cottbus.de/pub/postfix_tls/
PATCH_DIST_CAT.${TLS_PATCH}=	${TAR} -zxOf ${TLS_PATCH} "*/pfixtls.diff"
PATCH_DIST_STRIP.${TLS_PATCH}=	-p1
.  endif
CCARGS+=	-DHAS_SSL
AUXLIBS+=	-L${BUILDLINK_PREFIX.openssl}/lib			\
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib	\
		-lssl -lcrypto
PLIST_SRC+=	${PKGDIR}/PLIST.tls
MESSAGE_SRC+=	${PKGDIR}/MESSAGE.tls
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
.  include "../../databases/openldap/buildlink3.mk"
CCARGS+=	-DHAS_LDAP
AUXLIBS+=	-L${BUILDLINK_PREFIX.openldap}/lib			\
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openldap}/lib	\
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
### SASL support for SMTP authentication.  If neither SASLv1 or SASLv2 is
### explicitly specified, then build with SASLv2.
###
.if !empty(PKG_OPTIONS:Msasl)
.  if !defined(USE_SASL2) && !defined(USE_SASL)
.    include "../../security/cyrus-sasl2/buildlink3.mk"
BUILDLINK_INCDIRS.cyrus-sasl=	include/sasl
SASLLIBDIR=	${PREFIX}/lib/sasl2
PWCHECK_METHOD=	auxprop
CCARGS+=	-DUSE_SASL_AUTH
AUXLIBS+=	-L${BUILDLINK_PREFIX.cyrus-sasl}/lib			\
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.cyrus-sasl}/lib \
		-lsasl2
.  elif defined(USE_SASL2) && !empty(USE_SASL2:M[yY][eE][sS])
.    include "../../security/cyrus-sasl2/buildlink3.mk"
BUILDLINK_INCDIRS.cyrus-sasl=	include/sasl
SASLLIBDIR=	${PREFIX}/lib/sasl2
PWCHECK_METHOD=	auxprop
CCARGS+=	-DUSE_SASL_AUTH
AUXLIBS+=	-L${BUILDLINK_PREFIX.cyrus-sasl}/lib			\
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.cyrus-sasl}/lib \
		-lsasl2
.  elif defined(USE_SASL) && !empty(USE_SASL:M[yY][eE][sS])
.    include "../../security/cyrus-sasl/buildlink3.mk"
SASLLIBDIR=	${PREFIX}/lib/sasl
PWCHECK_METHOD=	sasldb
CCARGS+=	-DUSE_SASL_AUTH
AUXLIBS+=	-L${BUILDLINK_PREFIX.cyrus-sasl}/lib			\
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.cyrus-sasl}/lib \
		-lsasl
.  endif
PLIST_SRC+=	${PKGDIR}/PLIST.sasl
MESSAGE_SRC+=	${PKGDIR}/MESSAGE.sasl
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
MESSAGE_SUBST+=	SASLLIBDIR=${SASLLIBDIR}
.endif
