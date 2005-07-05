# $NetBSD: options.mk,v 1.7 2005/07/05 06:04:17 schmonz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ezmlm-idx
PKG_OPTIONS_OPTIONAL_GROUPS=	database
PKG_OPTIONS_GROUP.database=	mysql pgsql

.include "../../mk/bsd.options.mk"

###
### MySQL support
###
.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
.  if !target(post-configure)
post-configure:
	cd ${WRKSRC};							\
	${ECHO} -I${BUILDLINK_PREFIX.mysql-client}/include/mysql	\
		> sub_mysql/conf-sqlcc;					\
	${ECHO} -L${BUILDLINK_PREFIX.mysql-client}/lib/mysql 		\
		-Wl,-R${BUILDLINK_PREFIX.mysql-client}/lib/mysql	\
		-lmysqlclient						\
		> sub_mysql/conf-sqlld;					\
	${ECHO} mysql > conf-sub
.  else
PKG_FAIL_REASON+=	"ezmlm-idx: can't define post-configure mysql target"
.  endif
.endif

###
### PostgreSQL support
###
.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
.  if !target(post-configure)
post-configure:
	cd ${WRKSRC};							\
	${ECHO} -I${PGSQL_PREFIX}/include				\
		> sub_pgsql/conf-sqlcc;					\
	${ECHO} -L${PGSQL_PREFIX}/lib					\
		-Wl,-R${PGSQL_PREFIX}/lib				\
		-lpq							\
		> sub_pgsql/conf-sqlld;					\
	${ECHO} pgsql > conf-sub
.  else
PKG_FAIL_REASON+=	"ezmlm-idx: can't define post-configure pgsql target"
.  endif
.endif
