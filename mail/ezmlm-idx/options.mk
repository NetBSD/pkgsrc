# $NetBSD: options.mk,v 1.8 2005/07/14 03:49:40 schmonz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ezmlm-idx
PKG_OPTIONS_OPTIONAL_GROUPS=	database
PKG_OPTIONS_GROUP.database=	mysql pgsql

.include "../../mk/bsd.options.mk"

###
### MySQL support
###
.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
DJB_CONFIG_CMDS=							\
	${ECHO} ${CPPFLAGS} > sub_mysql/conf-sqlcc;			\
	${ECHO} ${LDFLAGS} -lmysqlclient > sub_mysql/conf-sqlld;	\
	${ECHO} mysql > conf-sub
.endif

###
### PostgreSQL support
###
.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
DJB_CONFIG_CMDS=							\
	${ECHO} ${CPPFLAGS} > sub_pgsql/conf-sqlcc;			\
	${ECHO} ${LDFLAGS} -lpq > sub_pgsql/conf-sqlld;			\
	${ECHO} pgsql > conf-sub
.endif
