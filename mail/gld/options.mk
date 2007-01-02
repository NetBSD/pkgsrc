# $NetBSD: options.mk,v 1.7 2007/01/02 11:47:40 ghen Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gld
PKG_OPTIONS_REQUIRED_GROUPS=	database
PKG_OPTIONS_GROUP.database=	mysql pgsql
PKG_SUGGESTED_OPTIONS=		mysql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}
LIBS+=			-L${BUILDLINK_PREFIX.mysql-client}/lib \
	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.mysql-client}/lib -lmysqlclient
MESSAGE_SRC+=		MESSAGE.mysql
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pgsql=${BUILDLINK_PREFIX.postgresql-libs}
LIBS+=			-L${BUILDLINK_PREFIX.mysql-client}/lib \
	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.mysql-client}/lib -lpq
# Replace rc.d dependency by pgsql
SUBST_CLASSES+=		pgsql
SUBST_STAGE.pgsql=	pre-install
SUBST_FILES.pgsql=	../gld
SUBST_SED.pgsql=	-e "s,mysqld,pgsql,"
.endif
