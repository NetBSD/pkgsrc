# $NetBSD: options.mk,v 1.4 2004/11/17 19:56:49 xtraeme Exp $

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
	${ECHO} -I${BUILDLINK_PREFIX.mysql-client}/include/mysql > ${WRKSRC}/sub_mysql/conf-sqlcc
	${ECHO} -L${BUILDLINK_PREFIX.mysql-client}/lib/mysql -Wl,-R${BUILDLINK_PREFIX.mysql-client}/lib/mysql -lmysqlclient > ${WRKSRC}/sub_mysql/conf-sqlld
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} mysql
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
	${ECHO} -I${PGSQL_PREFIX}/include > ${WRKSRC}/sub_pgsql/conf-sqlcc
	${ECHO} -L${PGSQL_PREFIX}/lib -Wl,-R${PGSQL_PREFIX}/lib -lpq > ${WRKSRC}/sub_pgsql/conf-sqlld
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} pgsql
.  else
PKG_FAIL_REASON+=	"pgsql: can't define post-configure target"
.  endif
.endif
