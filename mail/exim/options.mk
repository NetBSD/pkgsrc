# $NetBSD: options.mk,v 1.1 2005/09/10 23:11:40 abs Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.exim
PKG_SUPPORTED_OPTIONS=	content_scan gdmb lookup_dsearch lookup_whoson
PKG_SUPPORTED_OPTIONS+=	old_demime saslauthd
PKG_SUGGESTED_OPTIONS=	content_scan lookup_dsearch old_demime

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlookup_dsearch)
LOCAL_MAKEFILE_OPTIONS+=LOOKUP_DSEARCH=YES
.endif

.if !empty(PKG_OPTIONS:Mlookup_whoson)
LOCAL_MAKEFILE_OPTIONS+=WITH_LOOKUP_WHOSON=YES
LOOKUP_LIBS+=${COMPILER_RPATH_FLAG}${LOCALBASE}/${BUILDLINK_LIBDIRS.whoson} -L${LOCALBASE}/${BUILDLINK_LIBDIRS.whoson} -lwhoson
.  include "../../net/whoson/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mcontent_scan)
LOCAL_MAKEFILE_OPTIONS+=WITH_CONTENT_SCAN=YES
.endif

.if !empty(PKG_OPTIONS:Mold_demime)
LOCAL_MAKEFILE_OPTIONS+=WITH_OLD_DEMIME=YES
.endif

.if !empty(PKG_OPTIONS:Msaslauthd)
LOCAL_MAKEFILE_OPTIONS+=AUTH_CYRUS_SASL=YES
LOCAL_MAKEFILE_OPTIONS+=CYRUS_SASLAUTHD_SOCKET=/var/state/saslauthd/mux
LOOKUP_LIBS+=${COMPILER_RPATH_FLAG}${LOCALBASE}/${BUILDLINK_LIBDIRS.cyrus-sasl2} -L${LOCALBASE}/${BUILDLINK_LIBDIRS.cyrus-sasl2} -lsasl2
.  include "../../security/cyrus-sasl2/buildlink3.mk"
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
