# $NetBSD: options.mk,v 1.5 2014/11/02 05:55:43 obache Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.freeradius
PKG_SUPPORTED_OPTIONS=		freeradius-simul-use kerberos ldap mysql
PKG_SUPPORTED_OPTIONS+=		pam perl pgsql snmp
PKG_OPTIONS_OPTIONAL_GROUPS=	dbm odbc
PKG_OPTIONS_GROUP.dbm=		bdb gdbm
PKG_OPTIONS_GROUP.odbc=		iodbc unixodbc
PKG_SUGGESTED_OPTIONS=		freeradius-simul-use gdbm

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	dbm gdbm iodbc ldap kerberos mysql pam pgsql unixodbc perl

###
### GDBM or Berkeley DB 1.x support
###
.if !empty(PKG_OPTIONS:Mgdbm)
.  include "../../databases/gdbm/buildlink3.mk"
CONFIGURE_ARGS+=	--with-rlm_dbm
PLIST.dbm=		yes
PLIST.gdbm=		yes
.elif !empty(PKG_OPTIONS:Mbdb) && exists(/usr/include/ndbm.h)
BDB_ACCEPTED=		db1
.  include "../../mk/bdb.buildlink3.mk"
CONFIGURE_ARGS+=	--with-rlm_dbm
PLIST.dbm=		yes
.else
CONFIGURE_ARGS+=	--without-rlm_dbm
.endif

###
### PERL support
###
.if !empty(PKG_OPTIONS:Mperl)
.  include "../../lang/perl5/buildlink3.mk"
CONFIGURE_ARGS+=	--with-rlm_perl
PLIST.perl=		yes
.else
CONFIGURE_ARGS+=	--without-rlm_perl
.endif

###
### OpenLDAP support
###
.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-rlm_ldap
PLIST.ldap=		yes
.else
CONFIGURE_ARGS+=	--without-rlm_ldap
.endif

###
### IODBC support
###
.if !empty(PKG_OPTIONS:Miodbc)
.  include "../../databases/iodbc/buildlink3.mk"
CONFIGURE_ARGS+=	--with-rlm_sql_iodbc
PLIST.iodbc=		yes
.else
CONFIGURE_ARGS+=	--without-rlm_sql_iodbc
.endif

###
### UnixDBC support
###
.if !empty(PKG_OPTIONS:Munixodbc)
.  include "../../databases/unixodbc/buildlink3.mk"
CONFIGURE_ARGS+=	--with-rlm_sql_unixodbc
PLIST.unixodbc=		yes
.else
CONFIGURE_ARGS+=	--without-rlm_sql_unixodbc
.endif

###
### PostgreSQL support
###
.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-rlm_sql_postgresql
PLIST.pgsql=		yes
.else
CONFIGURE_ARGS+=	--without-rlm_sql_postgresql
.endif

###
### MySQL support
###
.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-rlm_sql_mysql
PLIST.mysql=		yes
.else
CONFIGURE_ARGS+=	--without-rlm_sql_mysql
.endif

###
### SNMP support
###
### Please note that snmp support is limited.  Freeradius looks like it's
### after the old ucd-snmp (v4.x) headers and ucd-snmp isn't in pkgsrc any
### more.  Compatability mode on the current net-snmp (v5.x) does not seem
### to work either.  So it will find a few snmp utilites but other than that
### it's limited, at best.
###
.if !empty(PKG_OPTIONS:Msnmp)
.  include "../../net/net-snmp/buildlink3.mk"
CONFIGURE_ARGS+=	--with-snmp
.else
CONFIGURE_ARGS+=	--without-snmp
.endif

###
### Kerberos 5 support
###
.if !empty(PKG_OPTIONS:Mkerberos)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--with-rlm_krb5
.  if defined(KRB5_TYPE) && ${KRB5_TYPE} == "heimdal"
CONFIGURE_ARGS+=	--enable-heimdal-krb5
.  endif
PLIST.kerberos=		yes
.else
CONFIGURE_ARGS+=	--without-rlm_krb5
.endif

###
### Enable Simultaneous-Use which needs snmpwalk and snmpget
###
.if !empty(PKG_OPTIONS:Mfreeradius-simul-use)
.  include "../../net/net-snmp/buildlink3.mk"
.else
CONFIGURE_ENV+=		ac_cv_path_SNMPGET=""
CONFIGURE_ENV+=		ac_cv_path_SNMPWALK=""
.endif

###
### PAM support
###
.if !empty(PKG_OPTIONS:Mpam)
CONFIGURE_ARGS+=	--with-rlm_pam
MESSAGE_SRC+=		${PKGDIR}/MESSAGE.pam
PLIST.pam=		yes
.else
CONFIGURE_ARGS+=	--without-rlm_pam
.endif
