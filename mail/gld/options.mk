# $NetBSD: options.mk,v 1.8 2020/11/01 14:21:43 spz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gld
PKG_OPTIONS_REQUIRED_GROUPS=	database
PKG_OPTIONS_GROUP.database=	mysql pgsql
PKG_SUGGESTED_OPTIONS=		mysql

BUILD_DEFS+=			GLDDB
FILES_SUBST+= 			GLDDB=${GLDDB}


.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
GLDDB=mysqld
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}
LIBS+=			-L${BUILDLINK_PREFIX.mysql-client}/lib \
	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.mysql-client}/lib -lmysqlclient
MESSAGE_SRC+=		MESSAGE.mysql
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
GLDDB=pgsql
CONFIGURE_ARGS+=	--with-pgsql=${BUILDLINK_PREFIX.postgresql-libs}
LIBS+=			-L${BUILDLINK_PREFIX.mysql-client}/lib \
	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.mysql-client}/lib -lpq
.endif
