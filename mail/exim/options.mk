# $NetBSD: options.mk,v 1.2 2005/10/03 18:45:50 abs Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.exim
PKG_SUPPORTED_OPTIONS=	exim-build-eximon exim-content-scan exim-lookup-dnsdb
PKG_SUPPORTED_OPTIONS+=	exim-lookup-dsearch exim-lookup-ldap exim-lookup-mysql
PKG_SUPPORTED_OPTIONS+= exim-lookup-whoson exim-old-demime gdbm saslauthd
PKG_SUGGESTED_OPTIONS=	exim-content-scan exim-lookup-dsearch exim-old-demime

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mexim-build-eximon)
LOCAL_MAKEFILE_OPTIONS+=EXIM_MONITOR=eximon.bin
USE_X11BASE=yes
.endif

.if !empty(PKG_OPTIONS:Mexim-content-scan)
LOCAL_MAKEFILE_OPTIONS+=WITH_CONTENT_SCAN=YES
.endif

.if !empty(PKG_OPTIONS:Mexim-lookup-dnsdb)
LOCAL_MAKEFILE_OPTIONS+=LOOKUP_DNSDB=YES
.endif

.if !empty(PKG_OPTIONS:Mexim-lookup-dsearch)
LOCAL_MAKEFILE_OPTIONS+=LOOKUP_DSEARCH=YES
.endif

.if !empty(PKG_OPTIONS:Mexim-lookup-ldap)
LOCAL_MAKEFILE_OPTIONS+=LOOKUP_LDAP=YES
LOCAL_MAKEFILE_OPTIONS+=LDAP_LIB_TYPE=OPENLDAP2
LOOKUP_LIBS+=${COMPILER_RPATH_FLAG}${LOCALBASE}/${BUILDLINK_LIBDIRS.openldap}  -L${LOCALBASE}/${BUILDLINK_LIBDIRS.openldap} -lldap -llber 
.  include "../../databases/openldap/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mexim-lookup-mysql)
LOCAL_MAKEFILE_OPTIONS+=LOOKUP_MYSQL=YES
LOOKUP_LIBS+=${COMPILER_RPATH_FLAG}${LOCALBASE}/${BUILDLINK_LIBDIRS.mysql}  -L${LOCALBASE}/${BUILDLINK_LIBDIRS.mysql} -lmysqlclient
.  include "../../mk/mysql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mexim-lookup-whoson)
LOCAL_MAKEFILE_OPTIONS+=LOOKUP_WHOSON=YES
LOOKUP_LIBS+=${COMPILER_RPATH_FLAG}${LOCALBASE}/${BUILDLINK_LIBDIRS.whoson} -L${LOCALBASE}/${BUILDLINK_LIBDIRS.whoson} -lwhoson
.  include "../../net/whoson/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mexim-old-demime)
LOCAL_MAKEFILE_OPTIONS+=WITH_OLD_DEMIME=YES
.endif

.if !empty(PKG_OPTIONS:Mgdbm)
.  include "../../databases/gdbm/buildlink3.mk"
EXIM_USE_DB_CONFIG=	USE_GDBM=yes
EXIM_DBMLIB=		DBMLIB=${LDFLAGS} -lgdbm
EXIM_INCLUDE=		-I${PREFIX}/include
.else # use native or Berkeley DB as defined by BDB_DEFAULT and BDB_ACCEPTED
.  include "../../mk/bdb.buildlink3.mk"
EXIM_USE_DB_CONFIG=	USE_DB=yes	# the default
.  if ${BDB_TYPE} == "db4"
EXIM_DBMLIB=		DBMLIB=${LDFLAGS} ${BDB_LIBS}
EXIM_INCLUDE=		-I${PREFIX}/${BUILDLINK_INCDIRS.db4}
.  elif ${BDB_TYPE} == "db3"
EXIM_DBMLIB=		DBMLIB=${LDFLAGS} ${BDB_LIBS}
EXIM_INCLUDE=		-I${PREFIX}/${BUILDLINK_INCDIRS.db3}
.  elif ${BDB_TYPE} == "db2"
EXIM_DBMLIB=		DBMLIB=${LDFLAGS} ${BDB_LIBS}
EXIM_INCLUDE=		-I${PREFIX}/${BUILDLINK_INCDIRS.db2}
.  else # using native
EXIM_DBMLIB=		# empty so use defaults
EXIM_USE_DB_CONFIG=	# empty so use defaults
EXIM_INCLUDE=		-I/usr/${BUILDLINK_INCDIRS.db-native}
.  endif
.endif

.if !empty(PKG_OPTIONS:Msaslauthd)
LOCAL_MAKEFILE_OPTIONS+=AUTH_CYRUS_SASL=YES
LOCAL_MAKEFILE_OPTIONS+=CYRUS_SASLAUTHD_SOCKET=/var/state/saslauthd/mux
LOOKUP_LIBS+=${COMPILER_RPATH_FLAG}${LOCALBASE}/${BUILDLINK_LIBDIRS.cyrus-sasl2} -L${LOCALBASE}/${BUILDLINK_LIBDIRS.cyrus-sasl2} -lsasl2
.  include "../../security/cyrus-sasl2/buildlink3.mk"
.endif
