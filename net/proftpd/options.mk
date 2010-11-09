# $NetBSD: options.mk,v 1.8.16.1 2010/11/09 20:58:59 spz Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.proftpd
PKG_SUGGESTED_OPTIONS=	pam inet6
PKG_SUPPORTED_OPTIONS=	pam inet6 wrap tls quota ldap proftpd-readme ban
PKG_OPTIONS_OPTIONAL_GROUPS+=	sql
PKG_OPTIONS_GROUP.sql=		mysql pgsql

.include "../../mk/bsd.options.mk"

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

.if !empty(PKG_OPTIONS:Mban)
MODULES:=	${MODULES}:mod_ban
.endif

.if !empty(MODULES)
CONFIGURE_ARGS+=	--with-modules=${MODULES:C/^://}
.endif
