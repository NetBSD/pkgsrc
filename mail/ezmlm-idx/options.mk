# $NetBSD: options.mk,v 1.6 2005/03/23 00:51:09 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ezmlm-idx
PKG_SUPPORTED_OPTIONS=	mysql pgsql
.include "../../mk/bsd.options.mk"

###
### We can't compile support for both MySQL and PostgreSQL.
###
.if !empty(PKG_OPTIONS:Mmysql) && !empty(PKG_OPTIONS:Mpgsql)
PKG_FAIL_REASON+=       "MySQL and PostgreSQL cannot both be compiled in." \
			"Please change ${PKG_OPTIONS_VAR} to one or the other."
.endif


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
PKG_FAIL_REASON+=	"mysql: can't define post-configure target"
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
PKG_FAIL_REASON+=	"pgsql: can't define post-configure target"
.  endif
.endif
