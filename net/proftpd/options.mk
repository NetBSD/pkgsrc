# $NetBSD: options.mk,v 1.4 2005/11/25 17:20:10 martti Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.proftpd
PKG_SUPPORTED_OPTIONS=	pam wrap quota ldap proftpd-readme
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

.if !empty(PKG_OPTIONS:Mquota)
MODULES:=	${MODULES}:mod_quota
.endif

.if !empty(PKG_OPTIONS:Mldap)
MODULES:=	${MODULES}:mod_ldap
.include "../../databases/openldap/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmysql)
MODULES:=	${MODULES}:mod_sql:mod_sql_mysql
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
