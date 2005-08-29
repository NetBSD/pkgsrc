# $NetBSD: options.mk,v 1.5 2005/08/29 14:28:12 tv Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.freeradius
PKG_SUPPORTED_OPTIONS=	bdb gdbm ldap mysql pgsql snmp
PKG_SUGGESTED_OPTIONS=	gdbm

.include "../../mk/bsd.options.mk"

###
### Use GDBM or Berkeley DB 1.x for storing user details
###
.if !empty(PKG_OPTIONS:Mgdbm)
.  include "../../databases/gdbm/buildlink3.mk"
CONFIGURE_ARGS+=	--with-rlm_dbm
PLIST_SRC+=		${PKGDIR}/PLIST.dbm ${PKGDIR}/PLIST.gdbm
.elif !empty(PKG_OPTIONS:Mbdb) && exists(/usr/include/ndbm.h)
BDB_ACCEPTED=		db1
.  include "../../mk/bdb.buildlink3.mk"
CONFIGURE_ARGS+=	--with-rlm_dbm
PLIST_SRC+=		${PKGDIR}/PLIST.dbm
.else
CONFIGURE_ARGS+=	--without-rlm_dbm
.endif

###
### Use OpenLDAP for storing user details
###
.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap/buildlink3.mk"
CONFIGURE_ARGS+=	--with-rlm_ldap
PLIST_SRC+=		${PKGDIR}/PLIST.ldap
.else
CONFIGURE_ARGS+=	--without-rlm_ldap
.endif

###
### Use PostgreSQL for storing user details
###
.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-rlm_sql_postgresql
PLIST_SRC+=		${PKGDIR}/PLIST.pgsql
.else
CONFIGURE_ARGS+=	--without-rlm_sql_postgresql
.endif

###
### Use MySQL for storing user details
###
.if !empty(PKG_OPTIONS:Mmysql)
.	include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-rlm_sql_mysql
PLIST_SRC+=		${PKGDIR}/PLIST.mysql
.else
CONFIGURE_ARGS+=	--without-rlm_sql_mysql
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
.  include "../../net/net-snmp/buildlink3.mk"
CONFIGURE_ARGS+=	--with-snmp
.else
CONFIGURE_ARGS+=	--without-snmp
.endif
