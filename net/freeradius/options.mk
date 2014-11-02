# $NetBSD: options.mk,v 1.14 2014/11/02 05:53:48 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.freeradius

PKG_OPTIONS_OPTIONAL_GROUPS=	dbm
PKG_OPTIONS_GROUP.dbm=	bdb gdbm

PKG_SUPPORTED_OPTIONS=	ldap mysql pgsql snmp kerberos freeradius-simul-use pam
PKG_SUGGESTED_OPTIONS=	gdbm freeradius-simul-use

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
.  include "../../databases/openldap-client/buildlink3.mk"
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
.  include "../../mk/mysql.buildlink3.mk"
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

###
### Use kerberos 5
###
.if !empty(PKG_OPTIONS:Mkerberos)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--with-rlm_krb5
.  if defined(KRB5_TYPE) && ${KRB5_TYPE} == "heimdal"
CONFIGURE_ARGS+=	--enable-heimdal-krb5
.  endif
PLIST_SRC+=		${PKGDIR}/PLIST.kerberos
.else
CONFIGURE_ARGS+=	--without-rlm_krb5
.endif

###
### Enable Simultaneous-Use which needs snmpwalk and snmpget
###
.if !empty(PKG_OPTIONS:Mfreeradius-simul-use)
.  include "../../net/net-snmp/buildlink3.mk"
.else
CONFIGURE_ENV+=	ac_cv_path_SNMPGET=""
CONFIGURE_ENV+=	ac_cv_path_SNMPWALK=""
.endif

###
### Use PAM for storing user details
###
.if !empty(PKG_OPTIONS:Mpam)
CONFIGURE_ARGS+=	--with-rlm_pam
PLIST_SRC+=		${PKGDIR}/PLIST.pam
MESSAGE_SRC+=		MESSAGE.pam
.else
CONFIGURE_ARGS+=	--without-rlm_pam
.endif
