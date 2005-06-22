# $NetBSD: options.mk,v 1.1 2005/06/22 22:43:37 salo Exp $
#

PKG_OPTIONS_VAR       = PKG_OPTIONS.proftpd
PKG_SUPPORTED_OPTIONS = pam wrap quota

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpam)
CONFIGURE_ARGS+=	--enable-auth-pam
.include "../../mk/pam.buildlink3.mk"
.endif

MODULES=#defined

.if !empty(PKG_OPTIONS:Mwrap)
MODULES:=${MODULES}mod_wrap
.endif

.if !empty(PKG_OPTIONS:Mquota)
MODULES:=${MODULES}mod_quota
.endif

## .if defined(PROFTPD_USE_LDAP) && ${PROFTPD_USE_LDAP} == "YES"
## MODULES:=	${MODULES}:mod_ldap
## DEPENDS+=	openldap-[0-9]*:../../databases/openldap
## .endif
##
## .if defined(PROFTPD_USE_MYSQL) && ${PROFTPD_USE_MYSQL} == "YES"
## MODULES:=	${MODULES}:mod_sql:mod_sql_mysql
## DEPENDS+=	mysql-client-[0-9]*:../../databases/mysql-client
## .endif
##
## .if defined(PROFTPD_USE_POSTGRES) && ${PROFTPD_USE_POSTGRES} == "YES"
## MODULES:=	${MODULES}:mod_sql:mod_sql_postgres
## DEPENDS+=	postgresql-client-[0-9]*:../../databases/postgresql-client
## .endif
##
## .if defined(PROFTPD_USE_README) && ${PROFTPD_USE_README} == "YES"
## MODULES:=	${MODULES}:mod_readme
## .endif

.if !empty(MODULES)
CONFIGURE_ARGS+=	--with-modules=${MODULES}
.endif
