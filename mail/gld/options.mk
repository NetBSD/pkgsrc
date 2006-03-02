# $NetBSD: options.mk,v 1.4 2006/03/02 20:41:30 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gld
PKG_OPTIONS_REQUIRED_GROUPS=	database
PKG_OPTIONS_GROUP.database=	mysql pgsql
PKG_SUGGESTED_OPTIONS=		mysql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pgsql=${BUILDLINK_PREFIX.postgresql-libs}
.endif
