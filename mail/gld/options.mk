# $NetBSD: options.mk,v 1.5 2006/03/02 20:49:39 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gld
PKG_OPTIONS_REQUIRED_GROUPS=	database
PKG_OPTIONS_GROUP.database=	mysql pgsql
PKG_SUGGESTED_OPTIONS=		mysql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}
LIBS+=			-L${BUILDLINK_PREFIX.mysql-client}/lib \
			-Wl,-R${BUILDLINK_PREFIX.mysql-client}/lib -lmysqlclient
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pgsql=${BUILDLINK_PREFIX.postgresql-libs}
LIBS+=			-L${BUILDLINK_PREFIX.mysql-client}/lib \
			-Wl,-R${BUILDLINK_PREFIX.mysql-client}/lib -lpq
.endif
