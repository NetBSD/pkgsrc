# $NetBSD: options.mk,v 1.1 2013/03/13 03:31:40 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.cyrus-sasl
PKG_OPTIONS_REQUIRED_GROUPS=	database
PKG_OPTIONS_GROUP.database=	ndbm bdb gdbm

.if defined(SASL_DBTYPE)
PKG_OPTIONS_DEPRECATED_WARNINGS+=	"Deprecated SASL_DBTYPE variable used, use ${PKG_OPTIONS_VAR:Q} instead (${PKG_OPTIONS_GROUP.database:ts,:Q})."
.  if !empty(SASL_DBTYPE:Mndbm)
PKG_SUGGESTED_OPTIONS+=	ndbm
.  elif !empty(SASL_DBTYPE:Mberkeley)
PKG_SUGGESTED_OPTIONS+=	bdb
.  else
PKG_FAIL_REASON+=			"Unknown SASL_DBTYPE: ${SASL_DBTYPE:Q}"
.  endif
.elif exists(/usr/include/ndbm.h) && ${OPSYS} != "Linux"
PKG_SUGGESTED_OPTIONS+=	ndbm
.else
PKG_SUGGESTED_OPTIONS+=	bdb
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mndbm)
SASL_DBTYPE=		ndbm
FILES_SUBST+=		DBEXT=.db
.elif !empty(PKG_OPTIONS:Mbdb)
SASL_DBTYPE=		berkeley
FILES_SUBST+=		DBEXT=
BDB_ACCEPTED=		db3 db4 db5
.  include "../../mk/bdb.buildlink3.mk"
CONFIGURE_ENV+=		with_bdb=${BDB_TYPE}
.elif !empty(PKG_OPTIONS:Mgdbm)
SASL_DBTYPE=		gdbm
FILES_SUBST+=		DBEXT=
.  include "../../databases/gdbm/buildlink3.mk"
.endif

CONFIGURE_ARGS+=	--with-dblib=${SASL_DBTYPE:Q}
CONFIGURE_ARGS+=	--with-dbpath=${PKG_SYSCONFDIR}/sasldb
