# $NetBSD: options.mk,v 1.7 2007/01/24 05:22:01 martti Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.proftpd
PKG_SUPPORTED_OPTIONS=	pam wrap quota ldap proftpd-readme tls
PKG_OPTIONS_OPTIONAL_GROUPS+=	sql
PKG_OPTIONS_GROUP.sql=		mysql pgsql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpam)
CONFIGURE_ARGS+=	--enable-auth-pam
.include "../../mk/pam.buildlink3.mk"
.endif

MODULES=	# empty

.if !empty(PKG_OPTIONS:Mwrap)
MODULES:=	${MODULES}:mod_wrap
.endif

.if !empty(PKG_OPTIONS:Mtls)
MODULES:=	${MODULES}:mod_tls
.include "../../security/openssl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mquota)
MODULES:=	${MODULES}:mod_quotatab:mod_quotatab_file
PLIST_SRC+=	${PKGDIR}/PLIST.mod_quota
.endif

.if !empty(PKG_OPTIONS:Mquota) && !empty(PKG_OPTIONS:Mmysql)
MODULES:=	${MODULES}:mod_quotatab_sql
.endif

.if !empty(PKG_OPTIONS:Mquota) && !empty(PKG_OPTIONS:Mpgsql)
MODULES:=	${MODULES}:mod_quotatab_sql
.endif

.if !empty(PKG_OPTIONS:Mquota) && !empty(PKG_OPTIONS:Mldap)
MODULES:=	${MODULES}:mod_quotatab_ldap
.endif

.if !empty(PKG_OPTIONS:Mldap)
MODULES:=	${MODULES}:mod_ldap
.include "../../databases/openldap-client/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmysql)
MODULES:=	${MODULES}:mod_sql:mod_sql_mysql
PLIST_SRC+=	${PKGDIR}/PLIST.mod_sql
.include "../../mk/mysql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
MODULES:=	${MODULES}:mod_sql:mod_sql_postgres
.include "../../mk/pgsql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mproftpd-readme)
MODULES:=	${MODULES}:mod_readme
.endif

.if !empty(MODULES)
CONFIGURE_ARGS+=	--with-modules=${MODULES:C/^://}
.endif
