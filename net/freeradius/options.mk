# $NetBSD: options.mk,v 1.1 2004/10/02 12:06:03 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.freeradius
PKG_SUPPORTED_OPTIONS=	ldap postgresql73 postgresql74 mysql4 mysql3 snmp

.include "../../mk/bsd.options.mk"

###
### Can't support both versions of PostgreSQL
###
.if !empty(PKG_OPTIONS:Mpostgresql73) && !empty(PKG_OPTIONS:Mpostgresql74)
PKG_FAIL_REASON+=	"PostgreSQL 7.3 and 7.4 cannot both be compiled in." \
			"Please change ${PKG_OPTIONS_VAR} to one or the other."
.endif

###
### Can't support both versions of mySQL
###
.if !empty(PKG_OPTIONS:Mmysql3) && !empty(PKG_OPTIONS:Mmysql4)
PKG_FAIL_REASON+=	"mySQL 3 and 4 cannot both be compiled in." \
			"Please change ${PKG_OPTIONS_VAR} to one or the other."
.endif

###
### Use OpenLDAP for storing user details
###
.if !empty(PKG_OPTIONS:Mldap)
.	include "../../databases/openldap/buildlink3.mk"
CONFIGURE_ARGS+=	--with-rlm_ldap
PLIST_SRC+=		${PKGDIR}/PLIST.ldap
.endif

###
### Use PostgreSQL v7.3 for storing user details
###
.if !empty(PKG_OPTIONS:Mpostgresql73)
.	include "../../databases/postgresql73-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-rlm_sql_postgresql
PLIST_SRC+=		${PKGDIR}/PLIST.pgsql
.endif

###
### Use PostgreSQL v7.4 for storing user details
###
.if !empty(PKG_OPTIONS:Mpostgresql74)
.	include "../../databases/postgresql74-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-rlm_sql_postgresql
PLIST_SRC+=		${PKGDIR}/PLIST.pgsql
.endif

###
### Use mySQL v4.x for storing user details
###
.if !empty(PKG_OPTIONS:Mmysql4)
.	include "../../databases/mysql4-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-rlm_sql_mysql
PLIST_SRC+=		${PKGDIR}/PLIST.mysql
.endif

###
### Use mySQL v3.x for storing user details
###
.if !empty(PKG_OPTIONS:Mmysql3)
.	include "../../databases/mysql-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-rlm_sql_mysql
PLIST_SRC+=		${PKGDIR}/PLIST.mysql
.endif

###
### Compile in SNMP support
###
### Please note that snmp support is limited.  Freeradius looks like it's 
### after the old ucd-snmp (v4.x) headers and ucd-snmp isn't in pkgsrc any
### more.  Compatability mode on the current net-snmp (v5.x) does not seem
### to work either.  So it will find a few snmp utilites but other than that
### it's limited, at best.
###
###
.if !empty(PKG_OPTIONS:Msnmp)
.	include "../../net/net-snmp/buildlink3.mk"
CONFIGURE_ARGS+=	--with-snmp
.endif
