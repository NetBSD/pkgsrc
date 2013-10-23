# $NetBSD: options.mk,v 1.12 2013/10/23 15:46:22 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.proftpd
PKG_SUPPORTED_OPTIONS=	pam inet6 wrap tls quota ldap proftpd-readme ban
PKG_OPTIONS_OPTIONAL_GROUPS+=	sql
PKG_OPTIONS_GROUP.sql=		mysql pgsql
PKG_SUGGESTED_OPTIONS=	pam inet6

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	quota sql tls

.if !empty(PKG_OPTIONS:Mpam)
CONFIGURE_ARGS+=	--enable-auth-pam
.include "../../mk/pam.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-auth-pam
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

MODULES=	# empty

.if !empty(PKG_OPTIONS:Mwrap)
MODULES:=	${MODULES}:mod_wrap
.include "../../security/tcp_wrappers/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mtls)
MODULES:=	${MODULES}:mod_tls
PLIST.tls=	yes
.include "../../security/openssl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mquota)
MODULES:=	${MODULES}:mod_quotatab:mod_quotatab_file
PLIST.quota=	yes
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
PLIST.sql=	yes
.include "../../mk/mysql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
MODULES:=	${MODULES}:mod_sql:mod_sql_postgres
PLIST.sql=	yes
.include "../../mk/pgsql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mproftpd-readme)
MODULES:=	${MODULES}:mod_readme
.endif

.if !empty(PKG_OPTIONS:Mban)
MODULES:=	${MODULES}:mod_ban
.endif

.if !empty(MODULES)
CONFIGURE_ARGS+=	--with-modules=${MODULES:C/^://}
.endif
